# Prisoner's Dilemma Simulation

> **Academic Disclaimer**: This was a college project for studying evolutionary game theory. The code is educational and experimental in nature - don't take it too seriously! It was created as a learning exercise to understand the dynamics of cooperation and defection in game theory.

## Overview

This repository contains two C implementations simulating the **Prisoner's Dilemma**, a fundamental concept in game theory that analyzes why individuals might not cooperate even when it's in their best interest.

The simulations model how cooperation evolves in a population over time under different spatial and non-spatial conditions.

## What is the Prisoner's Dilemma?

The Prisoner's Dilemma is a game theory scenario where two individuals can either **cooperate** or **defect**. The payoff matrix is structured such that:

- **R (Reward)**: Both cooperate → `b - c`
- **T (Temptation)**: You defect, opponent cooperates → `b`
- **S (Sucker's payoff)**: You cooperate, opponent defects → `-c`
- **P (Punishment)**: Both defect → `0`

Where:
- `b` = benefit of cooperation
- `c` = cost of cooperation

The dilemma arises because defecting is individually rational, but mutual cooperation yields better collective outcomes.

## Implementations

### 1. Non-Spatial Prisoner's Dilemma (`Non_Spatial_PD.c`)

A **well-mixed population** model where:
- Agents are randomly selected from the entire population
- No spatial structure or neighborhoods
- Agents compete in pairs and update strategies based on payoff differences
- Uses a probability function based on payoff differences to determine strategy adoption

**Key Features:**
- Population size: 1,000 agents
- Initial cooperation frequency: 50%
- Generations: 50 × population size
- Output: `FreqCoop.txt` (cooperation frequency over time)

### 2. Spatial Prisoner's Dilemma (`Spatial_PD.c`)

A **spatial grid model** where:
- Agents are arranged in an `n × n` grid (default: 50×50)
- Agents interact only with their 4 nearest neighbors (Von Neumann neighborhood)
- Uses periodic boundary conditions (grid wraps around)
- Strategy updates based on Fermi-Dirac probability function
- Spatial structure allows for cluster formation of cooperators

**Key Features:**
- Grid size: 50 × 50 (2,500 agents)
- Initial cooperation frequency: 50%
- Generations: 1,000 × population size
- Uses temperature parameter `k = 0.1` for strategy adoption
- Outputs:
  - `COOP_FREQ_B_[b]__C_[c].txt` - cooperation frequency over time
  - `INITIAL_MATRIX_B_[b]__C_[c].txt` - initial grid configuration
  - `FINAL_MATRIX_B_[b]__C_[c].txt` - final grid configuration

## Compilation and Execution

### Requirements
- GCC compiler (or any C compiler)
- Standard C libraries

### Compile

```bash
# Non-Spatial version
gcc Non_Spatial_PD.c -o non_spatial -lm

# Spatial version
gcc Spatial_PD.c -o spatial -lm
```

### Run

```bash
# Non-Spatial simulation
./non_spatial

# Spatial simulation
./spatial
```

## Parameters

Both programs use similar game theory parameters:

| Parameter | Description | Default Value |
|-----------|-------------|---------------|
| `b` | Benefit of cooperation | 2.0 |
| `c` | Cost of cooperation | 1.0 |
| `freq_coop` | Initial cooperation frequency | 0.5 (50%) |
| `gen_num` | Number of generations | 50 (non-spatial), 1000 (spatial) |
| `k` | Selection intensity (spatial only) | 0.1 |

### Modifying Parameters

To experiment with different parameters, edit the values in the `main()` function of each file before compiling.

## Output Files

### Non-Spatial
- **FreqCoop.txt**: Two columns `[generation] [cooperation_frequency]`

### Spatial
- **COOP_FREQ_B_[b]__C_[c].txt**: Cooperation frequency over time
- **INITIAL_MATRIX_B_[b]__C_[c].txt**: Initial grid (1 = cooperator, 0 = defector)
- **FINAL_MATRIX_B_[b]__C_[c].txt**: Final grid state

## Scientific Background

This simulation is based on evolutionary game theory research, particularly:

- **Nowak & May (1992)**: Showed that spatial structure can promote cooperation
- **Fermi-Dirac updating rule**: Mimics thermal noise in strategy adoption decisions
- The ratio `k = c/(b-c)` determines the critical cooperation threshold

## Results Interpretation

- **Non-spatial**: Typically leads to dominance of defectors (tragedy of the commons)
- **Spatial**: Spatial structure allows cooperators to form protective clusters, often maintaining stable cooperation levels

## Project Structure

```
dilema-prisioneiro/
├── Non_Spatial_PD.c       # Well-mixed population simulation
├── Spatial_PD.c           # Spatial grid simulation
├── README.md              # This file
├── LICENSE                # Project license
└── .gitignore            # Git ignore rules
```

## Known Limitations

As a college project, this code has some limitations:
- No command-line argument parsing
- Parameters are hardcoded
- Limited error handling
- No visualization tools (outputs are text files)
- Basic random number generation (not cryptographically secure)

## Future Improvements (if this weren't just a college project 😉)

- Add command-line parameter parsing
- Implement visualization with matplotlib or gnuplot
- Add more sophisticated updating rules
- Support for different network topologies
- Performance optimizations
- Statistical analysis tools

## License

See the [LICENSE](LICENSE) file for details.

## References

- Nowak, M. A., & May, R. M. (1992). Evolutionary games and spatial chaos. *Nature*, 359(6398), 826-829.
- Axelrod, R. (1984). *The Evolution of Cooperation*. Basic Books.
- Szabó, G., & Fath, G. (2007). Evolutionary games on graphs. *Physics Reports*, 446(4-6), 97-216.

---

**Note**: This project was created for educational purposes as part of a computational physics/game theory course. The code prioritizes clarity and learning over production-quality engineering practices.
