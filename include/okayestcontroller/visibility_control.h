#ifndef OKAYESTCONTROLLER__VISIBILITY_CONTROL_H_
#define OKAYESTCONTROLLER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define OKAYESTCONTROLLER_EXPORT __attribute__ ((dllexport))
    #define OKAYESTCONTROLLER_IMPORT __attribute__ ((dllimport))
  #else
    #define OKAYESTCONTROLLER_EXPORT __declspec(dllexport)
    #define OKAYESTCONTROLLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef OKAYESTCONTROLLER_BUILDING_LIBRARY
    #define OKAYESTCONTROLLER_PUBLIC OKAYESTCONTROLLER_EXPORT
  #else
    #define OKAYESTCONTROLLER_PUBLIC OKAYESTCONTROLLER_IMPORT
  #endif
  #define OKAYESTCONTROLLER_PUBLIC_TYPE OKAYESTCONTROLLER_PUBLIC
  #define OKAYESTCONTROLLER_LOCAL
#else
  #define OKAYESTCONTROLLER_EXPORT __attribute__ ((visibility("default")))
  #define OKAYESTCONTROLLER_IMPORT
  #if __GNUC__ >= 4
    #define OKAYESTCONTROLLER_PUBLIC __attribute__ ((visibility("default")))
    #define OKAYESTCONTROLLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define OKAYESTCONTROLLER_PUBLIC
    #define OKAYESTCONTROLLER_LOCAL
  #endif
  #define OKAYESTCONTROLLER_PUBLIC_TYPE
#endif
#endif  // OKAYESTCONTROLLER__VISIBILITY_CONTROL_H_
// Generated 16-Nov-2023 10:20:36
// Copyright 2019-2020 The MathWorks, Inc.
