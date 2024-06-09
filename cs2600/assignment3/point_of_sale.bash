#!/bin/sh

# Arguments (Fruit Prices)
apple=$1
banana=$2
orange=$3
kiwi=$4
watermelon=$5

# Global Vars
total_cost=0

# Menu Prompt
print_menu()
{
  echo "*** Welcome to the Fruit Vender Guild ***"
  echo "*** Select Fruits to buy ***"
  echo "(1) Apple"
  echo "(2) Banana"
  echo "(3) Orange"
  echo "(4) Kiwi"
  echo "(5) Watermelon"
  echo "(6) Checkout"
  echo "- Please select option (1-6):"
}

# CODE
print_menu
while read selection
do
  case $selection in
    1)
      echo '* Apple Selected (price: $'"$apple) *"
      echo "- Enter quantity: "
      read quantity
      (( total_cost += $quantity * $apple ))
      print_menu ;;
    2)
      echo '* Banana Selected (price: '"$banana) *"
      echo "- Enter quantity: "
      read quantity
      (( total_cost += $quantity * $banana ))
      print_menu ;;
    3)
      echo '* Orange Selected (price: '"$orange) *"
      echo "- Enter quantity: "
      read quantity
      (( total_cost += $quantity * $orange ))
      print_menu ;;
    4)
      echo '* Kiwi Selected (price: '"$kiwi) *"
      echo "- Enter quantity: "
      read quantity
      (( total_cost += $quantity * $kiwi ))
      print_menu ;;
    5)
      echo '* Watermelon Selected (price: '"$watermelon) *"
      echo "- Enter quantity: "
      read quantity
      (( total_cost += $quantity * $watermelon ))
      print_menu ;;
    6)
      echo '* Checkout Selected. Grand total: $'"$total_cost *"
      break ;;
    *)
      echo "ERROR: Unknown Selection!"
      print_menu ;;
  esac
done