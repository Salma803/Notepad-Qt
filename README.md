# QTextPad 🧩

QTextPad is a lightweight **Qt-based text editor** built in **C++**.  
It supports multiple documents via tabs, customizable fonts, and features such as search, replace, and line navigation.

---

## 🚀 Features

- Create, open, and save text files
- Manage **recent documents**
- Edit operations: **Cut, Copy, Paste, Undo, Redo, Select All**
- Change **font settings** and persist them between sessions
- Display **cursor position** (line and column)
- **Go to line** functionality
- **Search and replace** (case sensitive / insensitive)
- Manage **multiple tabs**
- Restore last used settings (recent docs, font, etc.)

---

## 🛠️ Technologies Used

- **Language:** C++
- **Framework:** Qt 5 / Qt 6
- **Modules:** QtWidgets, QtCore, QtGui
- **Tools:** Qt Creator, Git, GitHub

---

## 📦 Installation & Run

### Clone the repository

```bash
git clone https://github.com/Salma803/Notepad-Qt.git
cd Notepad-Qt
```


## 🏗️ Build and Run

### Using Qt Creator

1. Open the `.pro` (or `CMakeLists.txt`) file.  
2. Configure a Qt kit.  
3. Build and run the project.

### Or from the terminal

```bash
qmake && make
./QTextPad
``` 
---

## 🧠 Project Structure

```bash
📁 qtextpad/
┣━━ 📄 qtextpad.pro
┣━━ 📁 Headers/
│ ┣━━ mainwindow.h
│ ┣━━ numberedtextedit.h
│ ┗━━ replacedialog.h
┣━━ 📁 Sources/
│ ┣━━ main.cpp
│ ┣━━ mainwindow.cpp
│ ┣━━ numberedtextedit.cpp
│ ┗━━ replacedialog.cpp
┣━━ 📁 Forms/
│ ┣━━ mainwindow.ui
│ ┗━━ replacedialog.ui
┗━━ 📄 README.md
``` 

---
## 🧑‍💻 Author

Developed by Salma Azize
as part of the ENSIIE Qt programming project.
