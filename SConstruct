# R. Nowak, 2010-03-13   -*- mode: Python; -*-
#zaadaptowany na potrzeby naszego projektu
import os, shutil, platform, re

import SCons.Builder

def copyLibBuilder( target, source, env):
   '''kopiuje biblioteke'''
   shutil.copy( str(source[0]), str(target[0]) )
   return
env = Environment()

#sciezki
env.Append( ENV = {'PATH' : os.environ['PATH'] })
env.Append( BUILDERS = { } )

if(platform.system() == "Linux"):
   env.Append( CPPPATH = ['/usr/include/python2.7'] )
   env.Append( LIBPATH = ['/usr/lib/python2.7'] )

   env.Append( CPPFLAGS = '-Wall -pedantic -pthread' )
   env.Append( LINKFLAGS = '-Wall -pthread' )

   env.Append( LIBS = [ 'boost_python' ] )
elif(platform.system() == "Windows"):
   env.Append( CPPPATH = [ Dir('C:/Boost/include/boost-1_52'), #tutaj zainstalowane naglowki boost
                           Dir('C:/Python27/include') ] ) #tutaj zaistalowane naglowki python
   env.Append( LIBPATH = [ Dir('C:/Boost/lib'), #tutaj sciezka do bibliotek boost
                           Dir('C:/Python27/libs') ] ) #tutaj sciezki do bibliotek python

   env.Append( CPPFLAGS = ' /EHsc /MD /D "WIN32" /D "_CONSOLE" /W4' )
   env.Append( LINKFLAGS = ' /SUBSYSTEM:WINDOWS ' )
else:
   print platform.system() + " not supported"

#build C++ library
cpplib = env.SharedLibrary( target = 'hello', source = ['calculation/hello.cpp'])
if(platform.system() == "Linux"):
   target = 'calculation/hello.so'
elif(platform.system() == "Windows"):
   target = 'calculation/hello.pyd'
env.Command(target, cpplib, copyLibBuilder )
