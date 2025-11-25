# Contributing Guide

Thanks for your interest in this project! While this is primarily a college project for educational purposes, contributions are welcome if you'd like to improve it or use it for learning.

## Getting Started

### Prerequisites

- GCC compiler (or any standard C compiler)
- Basic understanding of game theory and the Prisoner's Dilemma
- Familiarity with C programming

### Development Setup

1. **Clone the repository**
   ```bash
   git clone https://github.com/leonardoxr/dilema-prisioneiro.git
   cd dilema-prisioneiro
   ```

2. **Compile the programs**
   ```bash
   # Non-Spatial version
   gcc Non_Spatial_PD.c -o non_spatial -lm

   # Spatial version
   gcc Spatial_PD.c -o spatial -lm
   ```

3. **Run the simulations**
   ```bash
   # Non-Spatial
   ./non_spatial

   # Spatial
   ./spatial
   ```

## Code Structure

### Non_Spatial_PD.c
- **main()**: Initializes parameters, runs simulation, outputs results
- **sum_array()**: Helper function to count cooperators in population

### Spatial_PD.c
- **main()**: Entry point, sets parameters, calls PD_DILEMMA
- **PD_DILEMMA()**: Main simulation function with spatial grid logic
- **sum_matrix()**: Counts cooperators in the grid
- **fermi_dirac()**: Strategy adoption probability function

## Making Changes

### Modifying Parameters

Parameters are defined in the `main()` function of each file:

```c
b = 2.0;           // Benefit of cooperation
c = 1.0;           // Cost of cooperation
gen_num = 1000;    // Number of generations
freq_coop = 0.5;   // Initial cooperation frequency (0.0 to 1.0)
```

For spatial simulations, you can also modify:
```c
#define n_ 50      // Grid size (n x n)
k = 0.1;           // Selection intensity
```

### Testing Changes

After making modifications:

1. **Recompile**
   ```bash
   gcc [modified_file].c -o [output_name] -lm
   ```

2. **Run simulation**
   ```bash
   ./[output_name]
   ```

3. **Check output files**
   - Non-spatial: `FreqCoop.txt`
   - Spatial: `COOP_FREQ_B_*.txt`, `INITIAL_MATRIX_B_*.txt`, `FINAL_MATRIX_B_*.txt`

## Compilation Flags

### Basic Compilation
```bash
gcc program.c -o program -lm
```

### With Warnings (Recommended)
```bash
gcc -Wall -Wextra program.c -o program -lm
```

### With Optimization
```bash
gcc -O2 program.c -o program -lm
```

### Debug Mode
```bash
gcc -g program.c -o program -lm
```

## Common Improvements

Here are some areas where contributions would be valuable:

### 1. Command-Line Arguments
Add argument parsing to allow parameter configuration without recompiling:
```bash
./spatial --benefit 3.0 --cost 1.5 --generations 5000
```

### 2. Visualization
Add scripts to visualize output data:
- Plot cooperation frequency over time
- Animate spatial grid evolution
- Heat maps of final states

### 3. Analysis Tools
Add statistical analysis:
- Calculate equilibrium cooperation levels
- Measure cluster sizes
- Compare different parameter regimes

### 4. Code Quality
- Add error handling for file operations
- Validate parameter ranges
- Improve random number generation (consider using better RNG)

### 5. Extended Models
- Different network topologies (Moore neighborhood, scale-free networks)
- Multiple strategies beyond cooperate/defect
- Mutation and noise
- Memory and reputation mechanisms

## Code Style

While this is a college project and doesn't enforce strict style guidelines, please:
- Use clear variable names
- Add comments for complex logic
- Keep functions focused and modular
- Follow existing indentation (spaces vs tabs)

## Output Files

All `.txt` output files are gitignored. If you need to share results:
- Create a `results/` or `data/` directory
- Update `.gitignore` to allow specific result files if needed
- Include a description of the parameters used

## Submitting Changes

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make your changes**
4. **Test thoroughly**
5. **Commit with clear messages**
   ```bash
   git commit -m "Add feature: description of what you added"
   ```

6. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

7. **Open a Pull Request**

## Running Different Scenarios

### High Cooperation Benefit
```c
b = 5.0;
c = 1.0;
// Expect more cooperation
```

### High Cost
```c
b = 2.0;
c = 1.5;
// Expect more defection
```

### Different Initial Conditions
```c
freq_coop = 0.1;   // Start with few cooperators
freq_coop = 0.9;   // Start with many cooperators
```

### Larger Grids (Spatial only)
```c
#define n_ 100     // Warning: significantly slower
```

## Troubleshooting

### Compilation Errors

**Error: undefined reference to 'exp'**
- Solution: Make sure to include `-lm` flag

**Error: 'for' loop initial declarations are only allowed in C99 mode**
- Solution: Add `-std=c99` flag or move variable declarations outside loops

### Runtime Issues

**No output files generated**
- Check write permissions in the directory
- Ensure the program runs to completion

**Unexpected results**
- Verify parameter values are reasonable
- Check that `freq_coop` is between 0 and 1
- Ensure `b > c` for proper Prisoner's Dilemma conditions

## Questions or Issues?

Since this is a college project, there's no formal support, but feel free to:
- Open an issue on GitHub
- Suggest improvements
- Share your experiments and results

## License

See [LICENSE](LICENSE) file for details.

---

Remember: This is an educational project. Experimentation and learning are encouraged!
