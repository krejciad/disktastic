# disktastic

**Disktastic** is a simple TUI (Terminal User Interface) tool for disk management on Arch Linux.  
It provides a fast, keyboard-driven way to inspect and manage disks directly from the terminal.

> ⚠️ Work in progress – use at your own risk.

## Features

- Terminal-based (TUI) interface
- Disk and partition overview
- Simple and intuitive keyboard navigation
- Built for Arch Linux / AUR users

## Screenshots

> Screenshots coming soon

![Main screen](docs/screenshots/main.png)
![Disk view](docs/screenshots/disk_view.png)
![Partition details](docs/screenshots/partition_details.png)

## Installation

### From AUR

Using an AUR helper (example with `yay`):

> Not ready yet, use Manual Build instead

```bash
yay -S disktastic
```

### Manual build

```bash
git clone https://github.com/krejciad/disktastic.git
cd disktastic
makepkg -si
```

## Usage

Run the application from your terminal:

```bash
disktastic
```

Most actions are accessible via keyboard shortcuts displayed in the UI.

## Requirements

- Arch Linux
- Root privileges (required for disk operations)
- A compatible terminal emulator

## Disclaimer

This tool interacts with disks and partitions.
Improper use may result in data loss.
Always double-check actions and make backups before using.

## Contributing

Contributions, issues, and feature requests are welcome.
Feel free to open an issue or submit a pull request.

## License

GNU GENERAL PUBLIC LICENSE, Version 3
