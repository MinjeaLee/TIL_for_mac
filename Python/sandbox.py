import tkinter as tk

root = tk.Tk()
root.title("Calculator")

e = tk.Entry(root, width=35, borderwidth=5)
e.grid(row=0, column=0, columnspan=3, padx=10, pady=10)


def button_click(number):
    current = e.get()
    e.delete(0, tk.END)
    e.insert(0, str(current) + str(number))


def button_clear():
    e.delete(0, tk.END)


def button_add():
    first_number = e.get()
    global f_num
    f_num = int(first_number)
    e.delete(0, tk.END)


def button_equal():
    second_number = e.get()
    e.delete(0, tk.END)
    e.insert(0, f_num + int(second_number))


# Define the buttons
button_1 = tk.Button(root, text="1", padx=40, pady=20,
                     command=lambda: button_click(1))
button_2 = tk.Button(root, text="2", padx=40, pady=20,
                     command=lambda: button_click(2))
button_3 = tk.Button(root, text="3", padx=40, pady=20,
                     command=lambda: button_click(3))
button_4 = tk.Button(root, text="4", padx=40, pady=20,
                     command=lambda: button_click(4))
button_5 = tk.Button(root, text="5", padx=40, pady=20,
                     command=lambda: button_click(5))
button_6 = tk.Button(root, text="6", padx=40, pady=20,
                     command=lambda: button_click(6))
button_7 = tk.Button(root, text="7", padx=40, pady=20,
                     command=lambda: button_click(7))
button_8 = tk.Button(root, text="8", padx=40, pady=20,
                     command=lambda: button_click(8))
button_9 = tk.Button(root, text="9", padx=40, pady=20,
                     command=lambda: button_click(9))
button_0 = tk.Button
