# Use an official lightweight Linux distribution as a base
FROM ubuntu:20.04

# Install flex and gcc
RUN apt-get update && apt-get install -y flex gcc

# Set the working directory inside the container
WORKDIR /app

# Copy your Lex file into the container
COPY . .

# Default command to run when the container starts
CMD ["bash"]
