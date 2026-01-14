import tkinter as tk
import random

# ---------- Functions ----------
def show_popup():
    popup = tk.Toplevel(root)
    popup.title("💖 Surprise!")
    popup.geometry("320x170")
    popup.configure(bg="#fff0f5")
    popup.resizable(False, False)

    label = tk.Label(
        popup,
        text="তোমার মনটা সত্যিই অনেক বড় 🥰\nএকটা ছোট ট্রিট দাও না 😄🍩",
        font=("Segoe UI", 14, "bold"),
        bg="#fff0f5",
        fg="#cc0066",
        justify="center"
    )
    label.pack(expand=True)

def move_button(event):
    card_width = 340
    card_height = 260

    btn_width = 90
    btn_height = 40

    x = random.randint(10, card_width - btn_width - 10)
    y = random.randint(120, card_height - btn_height - 10)

    no_button.place(x=x, y=y)

# ---------- Main Window ----------
root = tk.Tk()
root.title("Best Friend ❤️")
root.geometry("420x420")
root.configure(bg="#f2f2f2")
root.resizable(False, False)

# ---------- Card ----------
card = tk.Frame(root, bg="white")
card.place(relx=0.5, rely=0.5, anchor="center", width=340, height=260)

# ---------- Message ----------
question_label = tk.Label(
    card,
    text="তুমি আমার Best Friend 💕\nসবসময় হাসিখুশি থেকো 😊",
    font=("Segoe UI", 17, "bold"),
    bg="white",
    fg="#333333",
    justify="center"
)
question_label.pack(pady=25)

# ---------- Buttons ----------
yes_button = tk.Button(
    card,
    text="হ্যাঁ 🥰",
    font=("Segoe UI", 14, "bold"),
    bg="#ff5c8a",
    fg="white",
    bd=0,
    padx=25,
    pady=8,
    command=show_popup,
    cursor="hand2"
)
yes_button.pack(pady=10)

no_button = tk.Button(
    card,
    text="না 😜",
    font=("Segoe UI", 14, "bold"),
    bg="#cccccc",
    fg="#333333",
    bd=0,
    padx=25,
    pady=8,
    cursor="hand2"
)

no_button.place(x=130, y=170)
no_button.bind("<Enter>", move_button)

# ---------- Run App ----------
root.mainloop()
