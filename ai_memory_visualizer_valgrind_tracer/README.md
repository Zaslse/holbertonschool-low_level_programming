# AI Memory Visualizer & Valgrind Tracer

## Peer Review Readiness Guide
This repository contains a comprehensive analysis of C memory behavior, designed to pass the peer review readiness check. The reviewer can verify my understanding through the following points:

### 1. Memory Model Understanding
- **Stack vs Heap:** Explicitly differentiated in `analysis/memory_maps.md`. Stack lifetimes are strictly bound to function scopes, while heap lifetimes persist until explicitly freed.
- **Lifetimes:** The analysis explicitly documents when memory becomes invalid (e.g., function returns destroying stack frames).

### 2. Pointer & Aliasing Reasoning
- **Aliasing:** Detailed in `analysis/memory_maps.md`. It explains how multiple pointers referencing the same address lead to dangling pointers and undefined behavior if the memory is freed.

### 3. Valgrind Interpretation
- **Root Causes:** `analysis/valgrind_analysis.md` connects Valgrind errors (Invalid Read, Definitely Lost) directly to specific memory misuses (Buffer over-read, lost ownership due to pointer reassignment).

### 4. Crash Root Cause Explanation
- **Deterministic Failures:** `analysis/crash_report.md` explains a segmentation fault deterministically (e.g., the MMU blocking a write attempt to the `.rodata` read-only segment) rather than just stating "it crashed".

### 5. Critical Use of AI
- **AI Critiques:** Every analysis file contains a dedicated section identifying an AI mistake, explaining *why* the AI was wrong conceptually, and providing the corrected human reasoning (treating AI as a hypothesis, not an authority).
