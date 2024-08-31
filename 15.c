/*
============================================================================
Name : 15.c
Author : Mohit Marfatia
Description : Write a program to display the environmental variable of the user (use environ).
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>

extern char **environ;

int main(){
	char **env = environ;

	while(*env){
		printf("%s\n", *env);
		env++;
	}

	return 0;
}

/*
Output:
SHELL=/bin/bash
SESSION_MANAGER=local/mohit-marfatia:@/tmp/.ICE-unix/2092,unix/mohit-marfatia:/tmp/.ICE-unix/2092
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
SSH_AGENT_LAUNCHER=openssh
XDG_MENU_PREFIX=gnome-
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
CONDA_EXE=/home/mohit-marfatia/anaconda3/bin/conda
_CE_M=
GNOME_SHELL_SESSION_MODE=ubuntu
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
GTK_MODULES=gail:atk-bridge
PWD=/home/mohit-marfatia/College/Software-Systems/exercise
GSETTINGS_SCHEMA_DIR=/home/mohit-marfatia/anaconda3/share/glib-2.0/schemas
LOGNAME=mohit-marfatia
XDG_SESSION_DESKTOP=ubuntu
XDG_SESSION_TYPE=x11
CONDA_PREFIX=/home/mohit-marfatia/anaconda3
GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
SYSTEMD_EXEC_PID=4259
GSETTINGS_SCHEMA_DIR_CONDA_BACKUP=
XAUTHORITY=/run/user/1000/gdm/Xauthority
WINDOWPATH=2
HOME=/home/mohit-marfatia
USERNAME=mohit-marfatia
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=00:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.avif=01;35:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:*~=00;90:*#=00;90:*.bak=00;90:*.old=00;90:*.orig=00;90:*.part=00;90:*.rej=00;90:*.swp=00;90:*.tmp=00;90:*.dpkg-dist=00;90:*.dpkg-old=00;90:*.ucf-dist=00;90:*.ucf-new=00;90:*.ucf-old=00;90:*.rpmnew=00;90:*.rpmorig=00;90:*.rpmsave=00;90:
XDG_CURRENT_DESKTOP=ubuntu:GNOME
VTE_VERSION=7200
CONDA_PROMPT_MODIFIER=(base) 
GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/36a7d6e6_4bf4_4bcb_b2b1_21217880697d
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
TERM=xterm-256color
_CE_CONDA=
LESSOPEN=| /usr/bin/lesspipe %s
USER=mohit-marfatia
GNOME_TERMINAL_SERVICE=:1.114
CONDA_SHLVL=1
DISPLAY=:1
SHLVL=1
QT_IM_MODULE=ibus
CONDA_PYTHON_EXE=/home/mohit-marfatia/anaconda3/bin/python
XDG_RUNTIME_DIR=/run/user/1000
CONDA_DEFAULT_ENV=base
DEBUGINFOD_URLS=https://debuginfod.ubuntu.com 
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/mohit-marfatia/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
PATH=/home/mohit-marfatia/anaconda3/bin:/home/mohit-marfatia/anaconda3/condabin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
GDMSESSION=ubuntu
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
_=./a.out
*/
