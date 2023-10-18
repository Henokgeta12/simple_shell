#!/bin/bash
# Define the output file for the authors list in the project
AUTHORS_FILE="AUTHORS"

# Initialize an empty authors file
echo "# FILE @author_generate.sh. DO NOT EDIT ANY INFORMATION." > "$AUTHORS_FILE"
echo "# This file lists the contributors to the repository." >> "$AUTHORS_FILE"
echo "# See author_generate.sh to make modifications." >> "$AUTHORS_FILE"
echo "" >> "$AUTHORS_FILE"

# Use Git to get a list of contributors and append to the authors file
git log --format='%aN <%aE>' | sort -u >> "$AUTHORS_FILE"
echo "Authors file has been generated at $AUTHORS_FILE"
