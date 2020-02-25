#!/bin/sh

export GNUPGHOME=${GNUPGHOME:-$HOME/.gnupg}

mkdir -p -m go-rwx "$GNUPGHOME"
echo allow-preset-passphrase >> "$GNUPGHOME"/gpg-agent.conf || exit $?

gpg --import --batch "$1" || exit $?

keygrip=`gpg --list-secret-keys --with-colons "$GPG_USERNAME" | \
    awk -F : '$1 == "grp" { print $10 }'`
exec /usr/lib/gnupg/gpg-preset-passphrase --preset "$keygrip"
