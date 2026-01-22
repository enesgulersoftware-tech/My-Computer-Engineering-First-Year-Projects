import requests

# The site specified in the URL was used as an API. Calculations were made with the data obtained from there.
api_key = "YOUR_API_KEY_HERE" # You need to enter the API key obtained from the site here.
api_url = f"https://v6.exchangerate-api.com/v6/{api_key}/latest/"

# Currency conversion was performed with this function
def currency_converter(base_currency, target_currency, amount):
    response = requests.get(api_url + base_currency) # Appended the currency type to be sold to the end of the URL
    response_json = response.json() # Converted the incoming response to Python code using the json() method
    rate = response_json["conversion_rates"][target_currency] # Exchange rate information was retrieved here
    result = amount * rate # The amount to be received was calculated by multiplying the user's amount by the exchange rate
    print(f"1 {base_currency} = {rate} {target_currency}") # Printed exchange rate info to the screen
    print(f"Amount Received: {result} {target_currency}") # Printed the received amount to the screen


while(True):
    print("GULER EXCHANGE".center(50,"*"))
    while(True):
        try: # First, asked whether the user wants to perform a transaction
            choice = int(input("Do you want to make a transaction? \n1-) Yes 2-) No\nChoice: "))
            break
        except ValueError:
            print("Please Select One of the Specified Options!")
            
    if(choice == 1):
        base_currency = input("Enter the Currency Type to Sell: ").strip().upper()
        target_currency = input("Enter the Currency Type to Buy: ").strip().upper()
        while(True):
            try:
                amount = float(input("Amount to Sell: "))
                break
            except ValueError:
                print("Please Enter Integer Values!")
        currency_converter(base_currency, target_currency, amount) # Parameters passed to the function
    elif(choice == 2):
        break
    else:
        print("Please Enter a Valid Transaction Number!")
