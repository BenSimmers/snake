#!/bin/bash
#
# This script downloads and installs the latest release of the snake game.

set -e

# Determine the user's operating system.
if [[ "$(uname)" == "Darwin" ]]; then
  OS="macos-latest"
elif [[ "$(uname)" == "Linux" ]]; then
  OS="ubuntu-latest"
else
  echo "Unsupported operating system: $(uname)" >&2
  exit 1
fi

# Get the download URL for the correct binary.
DOWNLOAD_URL=$(curl -sL https://api.github.com/repos/BenSimmers/snake/releases/latest | grep "browser_download_url.*snake-$OS" | cut -d : -f 2,3 | tr -d '\"[:space:]')

if [ -z "$DOWNLOAD_URL" ]; then
  echo "Could not find a release for your operating system. Please check https://github.com/BenSimmers/snake/releases" >&2
  exit 1
fi

# Download the binary and make it executable.
echo "Downloading snake for $OS..."
curl -sL -o snake "$DOWNLOAD_URL"
chmod +x snake

echo "snake has been installed successfully. You can now run it with ./snake"
