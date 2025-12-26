FROM ubuntu:latest

# Install C++ tools and the PostgreSQL library (libpqxx)
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libpq-dev \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

# Compile the code
RUN mkdir -p build && cd build && cmake .. && make

# Run the application
CMD ["./build/sysprog_app"]
