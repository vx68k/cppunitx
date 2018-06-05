# Dockerfile for the CppUnitX builder image
# Copyright (C) 2018 Kaz Nishimura
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.

FROM gcc:7

RUN set -x && \
  apt-get update && \
  apt-get install --assume-yes --no-install-recommends \
    texinfo texlive && \
  rm -rf /var/lib/apt/lists/*

ENV TEX=dviluatex PDFTEX=luatex
