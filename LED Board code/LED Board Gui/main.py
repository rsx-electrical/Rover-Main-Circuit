import sys
from communications import write_read
from PyQt6.QtWidgets import QApplication, QLabel, QWidget, QPushButton, QMainWindow, QGridLayout
from PyQt6.QtGui import QFont
from PyQt6.QtCore import Qt

height = 400
width = int(16/9*height)

class mybutton(QPushButton):
    def __init__(self, p:QWidget, text:str, click):
        super().__init__(text, parent = p)
        self.setMinimumHeight(int((height-100)/4))
        self.setFont(QFont("Arial", 15))
        self.clicked.connect(click)

class Window(QMainWindow):
    def __init__(self):
        super().__init__(parent = None)
        self.setWindowTitle("LED Board GUI")
        central = QWidget(parent=self)
        self.setCentralWidget(central)
        self.setFixedWidth(width)
        self.setFixedHeight(height)

        # create grid layout
        self.grid = QGridLayout(parent=central)
        self.grid.setContentsMargins(50, 50, 50, 50)
        self.grid.setHorizontalSpacing(10)
        self.grid.setVerticalSpacing(10)

        # add header
        self.heading = QLabel("LED Board GUI", parent=central)
        self.heading.setFont(QFont("Arial", 30))
        self.heading.setMaximumHeight(30)
        self.grid.addWidget(self.heading, 1, 1, 1, 3, alignment=Qt.AlignmentFlag.AlignCenter)
        
        # add green, red, blue buttons
        text = ["Green", "Red", "Blue"]
        func = [self.greenOn, self.redOn, self.blueOn]
        for i in range(len(text)):
            self.grid.addWidget(mybutton(central, text[i], func[i]), 2, i+1)
        
        # add off button
        self.grid.addWidget(mybutton(central,"LEDs Off", self.allOff), 4, 1, 1, 3)
        
    # for text input
    # def greenOn(self, event=None):
    #     write_read('green\n')
    # def redOn(self, event=None):
    #     write_read('red\n')
    # def blueOn(self, event=None):
    #     write_read('blue\n')
    # def allOff(self, event=None):
    #     write_read('off\n')

    # for number input
    def greenOn(self, event=None):
        write_read('1\n')
    def redOn(self, event=None):
        write_read('2\n')
    def blueOn(self, event=None):
        write_read('3\n')
    def allOff(self, event=None):
        write_read('0\n')

        


if __name__ == "__main__":
    gui = QApplication([])
    window = Window()
    window.show()
    sys.exit(gui.exec())