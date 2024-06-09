// modem.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num_networks 10

typedef enum {kData, kWifi, kUnknown} MEDIUM;

typedef struct network {
 char* network_name;
 int signal_strength;
 MEDIUM connection_medium;
 bool password_saved;
} network;

struct network cached_networks[num_networks];

void ChooseNetwork(char* network) {
  printf("Network chosen: %s\n", network);
}

MEDIUM ConvertIntToMedium(int int_medium) {
  if (int_medium == 1) {
    return kData;
  } else if (int_medium == 2) {
    return kWifi;
  } else {
    return kUnknown;
  }
}

/**
  * TODO: This function is buggy and not complete
  *
  * We should first fix this function and then work on fixing ScanNetworksV2().
  * The fixes found in this function will help determine how to fix V2.
  */
void ScanNetworks()
{
  char *temp_network_name, *temp_password_saved;
  int medium;
  FILE *ed = fopen("experiment_data", "r");

  for (int i = 0; i < num_networks; i++) {
    temp_network_name = (char *)malloc(20 * sizeof(char));
    temp_password_saved = (char *)malloc(20 * sizeof(char));

    fscanf(ed, "%s", temp_network_name);
    fscanf(ed, "%d %d %19s", &medium,
                        &cached_networks[i].signal_strength,
                        temp_password_saved);

    cached_networks[i].network_name = (char*)malloc(strlen(temp_network_name) + 1);
    strcpy(cached_networks[i].network_name, temp_network_name);
    printf("%s\n", cached_networks[i].network_name);

    cached_networks[i].connection_medium = ConvertIntToMedium(medium);
}

  fclose(ed);
}

/**
  * This function early-exits from networks that we don't already have access
  * to. This way we can still scan for 5 networks, but we won't display/attempt
  * to make a decision vs networks we don't have the password for.

  * TODO: This function is buggy and not complete
  */
void ScanNetworksV2()
{
  char* network_name = (char*)malloc(20 * sizeof(char));
  char* password_saved = (char*)malloc(20 * sizeof(char));
  int signal_strength;
  int medium;
  int i = 0; // counter

  FILE *ed = fopen("experiment_data", "r");

  while (i < num_networks) {

    fscanf(ed, "%s %d %d %19s", network_name, &medium, &signal_strength,
                         password_saved);

    // Only cache networks we can't even connect to
    if (strcmp(password_saved, "true") == 0)
    {
      cached_networks[i].network_name = network_name;
      cached_networks[i].connection_medium = ConvertIntToMedium(medium);
      cached_networks[i].signal_strength = signal_strength;
      cached_networks[i].password_saved = (strcmp(password_saved, "true")==0);

      printf("%s\n", cached_networks[i].network_name);

      i++;
    }
  }

  fclose(ed);
}

void ScanNetworksV3() {
  // If you were to iterate and modify ScanNetworksV2 to be even better,
  // what would you do? You DO NOT need to write any code, you can just
  // explain what you would do or write psuedocode.
  }


// Made a method because I couldn't read it without some kind of separation :D
bool canConnect(struct network n, char* c)
{
        if (strcmp(c, "wifi")==0 && n.connection_medium==kWifi)
        {
                return true;
        }
        else if (strcmp(c, "data")==0 && n.connection_medium==kData)
        {
                return true;
        }
        else if (strcmp(c, "greedy")==0)
        {
                return true;
        }
        else
        {
                return false;
        }
}
/**
  * This function selects what network we should connect to based on certain
  * criteria.
  *
  * 1. We should only choose networks that we can connect to
  * 2. We should only connect to networks based on what criteria we want
  *    (i.e., Wi-Fi, Data, either).
  * 3. We should pick the network with the highest signal strength
  *
  * criteria    String denoting "wifi", "data", or "greedy"
  * return      String of best network_name
  */
char* DetermineNetwork(char* criteria) {
        // Iterate through cached_networks to choose the best network
        char *bestNetwork = (char*)malloc(20 * sizeof(char));
        int bestSignalStrength = 0;


        for (int i = 0; i < num_networks; i++)
        {
                // Connection Medium Check
                if (canConnect(cached_networks[i], criteria))
                {
                        // Signal Strength Check
                        if (cached_networks[i].signal_strength > bestSignalStrength)
                        {
                                strcpy(bestNetwork, cached_networks[i].network_name);
                                bestSignalStrength = cached_networks[i].signal_strength;
                        }
                }
        }

        // The best of the bestest best network wow :O
        return bestNetwork;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Incorrect command argument. Please pass in 'wifi', 'data', or 'greedy'\n");
    return 1;
  }

  printf("Starting up modem...\n");
  printf("Scanning nearby network connections...\n");
  ScanNetworks();
  printf("Networks cached. Now determining network to connect...\n");
  printf("Connection Medium Criteria: %s\n", argv[1]);
  ChooseNetwork(DetermineNetwork(argv[1]));

  return 0;
}