cmake_minimum_required(VERSION 3.24)

project(lpeg LANGUAGES C VERSION 0.1.0)

add_library(lpeg
  lpeg/lpcap.h lpeg/lpcap.c
  lpeg/lpcode.h lpeg/lpcode.c
  lpeg/lpcset.h lpeg/lpcset.c
  lpeg/lpprint.h lpeg/lpprint.c
  lpeg/lptree.h lpeg/lptree.c
  lpeg/lptypes.h
  lpeg/lpvm.h lpeg/lpvm.c
)
