class CheeseBrand:
    def __init__(self, brand, cost):
        self.brand = brand
        self.cost = cost
        self._immutable = True   

    def __setattr__(self, name, value):
        if getattr(self, '_immutable', False):  
            raise RuntimeError('This object is immutable')
        else:
            super(CheeseBrand, self).__setattr__(name, value)
    

class CheeseShop:
    menu = {}  
    
    def __init__(self):
        self.orders = {}  

    def addStock(self, brand, cost):
        cheese = CheeseBrand(brand, cost)
        self.menu[brand] = cheese   

    def sell(self, brand, units):
        self.orders.setdefault(brand, 0)
        self.orders[brand] += units   

    def totalSold(self):
        return sum(self.orders.values())
    
    def totalIncome(self):
        income = 0
        for brand, units in self.orders.items():
            income += self.menu[brand].cost * units
        return income


shop1 = CheeseShop()
shop2 = CheeseShop()

shop1.addStock('white', 1.25)
shop1.addStock('blue', 3.75)

shop1.sell('blue', 3)    
shop2.sell('blue', 8)    

print(shop1.totalSold())
print(shop1.totalIncome())
print(shop2.totalSold())
print(shop2.totalIncome())
