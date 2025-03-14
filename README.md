# Zephyr

A High-Performance C++ Web Framework.

### Project Structure

```bash
zephyr/                  # Root directory
│-- src/                 # Source code for the framework
│   ├── core/            # Core framework logic (HTTP server, middleware, routers)
│   │   ├── http/        # HTTP-related components (requests, responses, headers)
│   │   ├── routing/     # Routing system for handling requests
│   │   ├── middleware/  # Middleware components (logging, authentication, etc.)
│   │   ├── utils/       # Helper functions, utilities
│   │   ├── server.cpp   # Main server logic
│   │   ├── config.cpp   # Configuration management
│   │   └── main.cpp     # Entry point
│
│-- include/             # Public headers
│   ├── zephyrpp/        # Namespace for framework components
│   │   ├── http.hpp     # HTTP handling (requests, responses, etc.)
│   │   ├── router.hpp   # Routing logic
│   │   ├── middleware.hpp # Middleware utilities
│   │   ├── server.hpp   # Main server class
│   │   ├── config.hpp   # Configurations and settings
│-- examples/            # Sample apps and demos
│   ├── basic_server/    # A simple Zephyr server example
│   ├── rest_api/        # Example REST API
│   ├── websocket/       # WebSocket example  
│-- tests/               # Unit tests  
│   ├── CMakeLists.txt  
│   ├── test_server.cpp  
│   ├── test_routing.cpp  
│-- benchmarks/          # Performance benchmarks  
│   ├── benchmark.cpp  
│-- docs/                # Documentation files (README, API docs, etc.)  
│-- third_party/         # External dependencies, if needed  
│-- cmake/               # CMake-related scripts and configs  
│-- CMakeLists.txt       # Main CMake configuration file  
│-- README.md            # Project description, setup, and usage guide  
│-- .gitignore           # Ignored files for version control  
│-- LICENSE              # Open-source license  
```
