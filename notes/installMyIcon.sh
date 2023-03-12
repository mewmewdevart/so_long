#!/bin/bash

# Script para instalar a função de exibir um icone - nao funcionando
# Instalar dependências necessárias
sudo apt-get update
sudo apt-get install -y xdg-utils
# Outras dependências...

# Copiar arquivos do aplicativo para o sistema
sudo cp -r /caminho/do/aplicativo /usr/local/bin
sudo chmod +x /usr/local/bin/meu_aplicativo

# Copiar arquivo de ícone para a pasta de ícones padrão
sudo cp /caminho/do/arquivo_de_icone.xpm /usr/share/icons
sudo chmod 644 /usr/share/icons/arquivo_de_icone.xpm

# Criar arquivo .desktop para o aplicativo
sudo bash -c 'cat <<EOF > /usr/share/applications/meu_aplicativo.desktop
[Desktop Entry]
Name=Meu Aplicativo
Exec=/usr/local/bin/meu_aplicativo
Icon=/usr/share/icons/arquivo_de_icone.xpm
Type=Application
EOF'

# Instalar arquivo .desktop e definir o ícone
sudo xdg-desktop-icon install /usr/share/applications/meu_aplicativo.desktop --novendor --size 48 --mode system
