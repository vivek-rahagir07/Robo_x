# Contributing to Robotics Club

Welcome! We are excited to collaborate with club members and makers worldwide. Whether you are building an autonomous robot, documenting a circuit, refining CAD designs, or polishing code, your contributions are welcome.

---

## 🧭 How to Contribute

### 1. Propose or Pick an Issue
- Check the open issues or projects list.
- If you have an idea for a new robot or component guide, open an issue or discussion first so we can coordinate.

### 2. Branching Strategy
- Fork or branch off `main`.
- Use descriptive branch names:
  - `feature/line-follower-pid`
  - `electronics/esp32-shield-pcb`
  - `cad/robotic-arm-gripper`
  - `docs/troubleshooting-brownouts`

### 3. Commit Message Standards
Follow conventional commit formats:
- `feat(projects): add obstacle avoiding ultrasonic logic`
- `fix(electronics): correct motor driver pin assignment in schematic`
- `docs(software): add setup guide for ROS 2 on Raspberry Pi`

---

## 📁 Repository Standards by Domain

### 🤖 Projects (`projects/`)
Every project directory should include:
- `README.md`: Project summary, Bill of Materials (BOM), circuit pinout, and wiring instructions.
- Source code / firmware files (e.g. `.ino`, `.cpp`, `.py`).
- Circuit diagrams or schematics (or link to `electronics/`).
- 3D models or mechanical files (or link to `mechanical/`).

### ⚡ Electronics (`electronics/`)
- Schematics should ideally be in open formats (KiCad `.kicad_sch`, EasyEDA, or high-res exported `.png`/`.pdf`).
- Include a Bill of Materials (BOM) with part numbers, tolerances, and voltage/current ratings.
- Keep PCB design files accompanied by standard Gerber ZIP archives for fabrication.

### 💻 Software (`software/`)
- Write clean, commented code with descriptive variable names.
- For Python code, provide a `requirements.txt` or `pyproject.toml`.
- For Arduino/ESP32, document required libraries and board configuration (CPU frequency, partition scheme).

### 🛠️ Mechanical (`mechanical/`)
- Provide standard interchange formats (`.STEP`, `.STL`) in addition to native CAD files (`.sldprt`, `.f3d`).
- Always specify print settings (recommended layer height, infill %, wall thickness, supports).

---

## 🚀 Submitting a Pull Request (PR)
1. Ensure files are organized in the appropriate folders matching the repository structure.
2. Verify all markdown links work.
3. Test your code or design on actual hardware if possible.
4. Open a PR with a clear summary of what you built or changed, including photos or videos of the hardware in action if available.
