#!/bin/csh

# Arguments (Fruit Prices)
set apple = $1
set banana = $2
set orange = $3
set kiwi = $4
set watermelon = $5
# Global Vars
set total_cost = 0

# CODE
echo "*** Welcome to the Fruit Vender Guild ***"
echo "*** Select Fruits to buy ***"
echo "(1) Apple"
echo "(2) Banana"
echo "(3) Orange"
echo "(4) Kiwi"
echo "(5) Watermelon"
echo "(6) Checkout"
echo "- Please select option (1-6): "

while (1)
  set selection = $<
  switch ($selection)
    case 1:
      echo '* Apple Selected (price: $'"$apple) *"
      echo "- Enter quantity: "
      set quantity = $<
      @ total_cost = $total_cost + ($quantity * $apple)
      echo "*** Welcome to the Fruit Vender Guild ***"
      echo "*** Select Fruits to buy ***"
      echo "(1) Apple"
      echo "(2) Banana"
      echo "(3) Orange"
      echo "(4) Kiwi"
      echo "(5) Watermelon"
      echo "(6) Checkout"
      echo "- Please select option (1-6): "
      breaksw
    case 2:
      echo '* Banana Selected (price: $'"$banana) *"
      echo "- Enter quantity: "
      set quantity = $<
      @ total_cost = $total_cost + ($quantity * $banana)
      echo "*** Welcome to the Fruit Vender Guild ***"
      echo "*** Select Fruits to buy ***"
      echo "(1) Apple"
      echo "(2) Banana"
      echo "(3) Orange"
      echo "(4) Kiwi"
      echo "(5) Watermelon"
      echo "(6) Checkout"
      echo "- Please select option (1-6): "
      breaksw
    case 3:
      echo '* Orange Selected (price: $'"$orange) *"
      echo "- Enter quantity: "
      set quantity = $<
      @ total_cost = $total_cost + ($quantity * $orange)
      echo "*** Welcome to the Fruit Vender Guild ***"
      echo "*** Select Fruits to buy ***"
      echo "(1) Apple"
      echo "(2) Banana"
      echo "(3) Orange"
      echo "(4) Kiwi"
      echo "(5) Watermelon"
      echo "(6) Checkout"
      echo "- Please select option (1-6): "
      breaksw
    case 4:
      echo '* Kiwi Selected (price: $'"$kiwi) *"
      echo "- Enter quantity: "
      set quantity = $<
      @ total_cost = $total_cost + ($quantity * $kiwi)
      echo "*** Welcome to the Fruit Vender Guild ***"
      echo "*** Select Fruits to buy ***"
      echo "(1) Apple"
      echo "(2) Banana"
      echo "(3) Orange"
      echo "(4) Kiwi"
      echo "(5) Watermelon"
      echo "(6) Checkout"
      echo "- Please select option (1-6): "
      breaksw
    case 5:
      echo '* Watermelon Selected (price: $'"$watermelon) *"
      echo "- Enter quantity: "
      set quantity = $<
      @ total_cost = $total_cost + ($quantity * $watermelon)
      echo "*** Welcome to the Fruit Vender Guild ***"
      echo "*** Select Fruits to buy ***"
      echo "(1) Apple"
      echo "(2) Banana"
      echo "(3) Orange"
      echo "(4) Kiwi"
      echo "(5) Watermelon"
      echo "(6) Checkout"
      echo "- Please select option (1-6): "
      breaksw
    case 6:
      echo '* Checkout Selected. Grand total: $'"$total_cost *"
      break
    default:
      echo "ERROR: Unknown Selection"
      echo "*** Welcome to the Fruit Vender Guild ***"
      echo "*** Select Fruits to buy ***"
      echo "(1) Apple"
      echo "(2) Banana"
      echo "(3) Orange"
      echo "(4) Kiwi"
      echo "(5) Watermelon"
      echo "(6) Checkout"
      echo "- Please select option (1-6): "
      breaksw
  endsw
end