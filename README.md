# RISC-V-Edge-AI
**Course Project – VLSI System Design (VSD)**  

This repository documents my progress through the **RISC-V Edge AI Workflow** course.  
The project explores deploying **machine learning (ML) and neural networks** on the **SiFive FE310-G002 RISC-V SoC** (16 KB RAM).  

Since I did not have access to the physical board, all work — **training, quantization, inference, and image capture** — was carried out via **Freedom Studio** for bare-metal RISC-V builds.  

The core project is an **MNIST handwritten digit classifier**, trained and quantized in Python, then ported to a simulated bare-metal RISC-V environment for inference.  

---

##  Objectives
- Train and quantize a neural network for MNIST digit recognition  
- Optimize to fit ≤16 KB SRAM  
- Simulate deployment on SiFive FE310-G002 (no hardware needed)  
- Practice bare-metal programming and memory-aware inference  

---

## Course Modules (Highlights)
- Edge AI intro & VSDSquadron board overview  
- ML basics – regression, gradient descent, visualization  
- Classification – KNN, SVM, and embedded inference  
- MNIST with SVM and RISC-V simulation  
- Quantization for ≤16 KB SRAM  
- Neural networks – scratch to 98% accuracy  
- Bit-quantized NN deployment on RISC-V  

---

##  Hardware & Software
**Target Hardware (simulated):**  
- SiFive FE310-G002 (RV32IMAC, 320 MHz, 16 KB I-cache, 16 KB SRAM, QSPI Flash)  

**Tools & Software:**  
- Google Colab / Python 3.10+  
  - `tensorflow==2.15.0`, `numpy`, `matplotlib`  
- Freedom Studio 3.1.1 – RISC-V simulation/debugging  
- RISC-V GNU Toolchain (optional, CLI builds)  

---

##  Repository Structure
```
├── Datasheets/
│   ├── 50_Startups-*.csv
│   ├── Social_Network_Ads-*.csv
│   └── studentscores-*.csv
│
├── Google Colab Notebook/
│   ├── Digital_Recognition.ipynb
│   ├── Neural_Network.ipynb
│   ├── Reg&Op.ipynb
│   └── knn_and_svm.ipynb
│
├── Header/
│   ├── scaler.h
│   ├── scaler1.h
│   ├── svm_model.h
│   ├── svm_model1.h
│   └── test_images.h
│
├── MNIST/
│   ├── BitNetMCU_inference.c
│   ├── BitNetMCU_inference.h
│   └── code.c
│
├── NN Visualization/
│   ├── model1.png
│   ├── model2.png
│   ├── model3.png
│   └── t
│
├── Regression/
│   └── code.c
│
├── SVM/
│   ├── code1.c
│   ├── code2.c
│   └── code3.c
│
└── README.md
```
---

## Model Details

Input: 12×12 grayscale (downsized MNIST 28×28)
Hidden Layers: 2 × Dense (64 neurons, LeakyReLU)
Output: 10 neurons (digits 0–9)
Quantization: 8-bit, size ≈ 17 KB
Inference: Integer-only ops (ReLU + FC)

---

## Key Learnings

Built complete Edge AI pipeline without physical hardware
Quantized NN to fit ≤16 KB SRAM
Bare-metal RISC-V programming concepts
Preprocessing & UART image pipeline
Bridged Python ML ↔ Embedded C workflows

---

## Acknowledgments

VSD – course & mentorship
SiFive – FE310-G002 docs
TensorFlow Lite – quantization tools

---

## Status

Compiles cleanly (zero errors/warnings)
No hardware test (simulation only)
Still under development
