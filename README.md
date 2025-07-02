# snake

## Installation

You can download the latest release from the [releases page](https://github.com/BenSimmers/snake/releases).

Or using `curl`:

```bash
curl -sL -o snake $(curl -sL https://api.github.com/repos/BenSimmers/snake/releases/latest | grep "browser_download_url.*snake" | cut -d : -f 2,3 | tr -d '"')
```

Or using `wget`:

```bash
wget -O snake $(curl -s https://api.github.com/repos/BenSimmers/snake/releases/latest | grep "browser_download_url.*snake" | cut -d : -f 2,3 | tr -d '"')
```

After downloading, make the binary executable:

```bash
chmod +x snake
```

And run it:

```bash
./snake
```