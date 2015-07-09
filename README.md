# c
C++ with Financial Engineering Applications

## Mac Installation Guide

#### System Requirements
Make sure your system meets these requirements:
  - Operating system: MacOS 10.7 10.8 10.9 (it has been tested successfully on these)
  - RAM: 2GB.
  - Disk space: 2GB

#### Step 1: Install Command Line Tools
  - Open terminal, type “xcode-select --install” in terminal (without quotes)
  - A pop-up windows will appear asking you about install tools, choose install tools, wait install to finish
  
#### Step 2: Install Homebrew

  ```
  ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
  ```

#### Step 3: Install gcc and its libraries

  ```
  brew install gcc
  brew install boost
  brew install Eigen
  ```
  
#### Step 4: Install Sublime IDE and fix Mac Path

  ```
  brew cask install Caskroom/cask/sublime-text
  git clone https://github.com/weiyialanchen/MacInstallation.git ~/Library/Application\ Support/Sublime\ Text\ 2/Packages/FixMacPath
  ```

## Running Guide

#### Step 1: Open the terminal and clone this repository

  ```
  cd ~
  git clone https://github.com/weiyialanchen/c.git
  ```

#### Step 2: Copy the `makefile` at directory `hw_01_01` to the directory you are going to run, say `hw_01_02`

  ```
  cp ~/c/hw_01_01/makefile ~/c/hw_01_02/makefile
  ```
  
#### Step 3: complie with cpp script with the `makefile` and run

  ```
  cd ~/c/hw_01_02
  make
  ./hw_01_02
  ```
