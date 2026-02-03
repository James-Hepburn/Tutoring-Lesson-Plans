print("Currency Converter")
print("\nAvailable currencies: CAD, USD, GBP")

amount = float(input("\nEnter the amount: "))
from_currency = input("Enter the currency to convert from: ").upper()
to_currency = input("Enter the currency to convert to: ").upper()

# Exchange rates (Fictional rates for demonstration purposes)
cad_to_usd = 0.79
cad_to_gbp = 0.59
usd_to_cad = 1.27
usd_to_gbp = 0.74
gbp_to_cad = 1.69
gbp_to_usd = 1.35

if from_currency == "CAD" and to_currency == "USD":
    converted_amount = amount * cad_to_usd
elif from_currency == "CAD" and to_currency == "GBP":
    converted_amount = amount * cad_to_gbp
elif from_currency == "USD" and to_currency == "CAD":
    converted_amount = amount * usd_to_cad
elif from_currency == "USD" and to_currency == "GBP":
    converted_amount = amount * usd_to_gbp
elif from_currency == "GBP" and to_currency == "CAD":
    converted_amount = amount * gbp_to_cad
elif from_currency == "GBP" and to_currency == "USD":
    converted_amount = amount * gbp_to_usd
else:
    print("\nInvalid currencies.")

print ()
print(f"{amount:.2f} {from_currency} is equal to {converted_amount:.2f} {to_currency}.")
