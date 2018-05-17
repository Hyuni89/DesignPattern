class Image:
    def displayImage(self):
        pass

class RealImage(Image):
    filename = None
    def __init__(self, name):
        self.filename = name
        self.load()
    def load(self):
        print("Loading %s" % self.filename)
    def displayImage(self):
        print("Displaying %s" % self.filename)

class ProxyImage(Image):
    filename = None
    image = None
    def __init__(self, name):
        self.filename = name
    def displayImage(self):
        if self.image is None:
            print("in Proxy...", end=" ")
            self.image = RealImage(self.filename)
        self.image.displayImage()

i1 = ProxyImage("image_001")
i2 = ProxyImage("image_002")

i1.displayImage()
i1.displayImage()
i2.displayImage()
i2.displayImage()
i1.displayImage()
