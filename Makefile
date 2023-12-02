# GNU make can be found in the following locations;
#
#   c:\cygwin64\bin\    (As both make.exe and gmake.exe)
#   c:\nsys64\usr\bin\  (As only make.exe)


# ======================================
# Section 1)
# --------------------------------------
#
# Settings and flags associated with :
#
#   - Finding necessary files
#   - Miscellaneous utilities
# ======================================
# Converting Glade files from Gtk3
# format to Gtk4 format.
#
# c:\msys64\mingw64\bin\gtk4-builder-tool.exe simplify --3to4 <Name of ui file to convert>
# ======================================

vpath %.cpp src

pkgconfig=pkg-config


# ======================================
# Section 2)
# --------------------------------------
#
# Settings and flags associated with :
#
#   - Compilation process
#   - Linking process
# ======================================
# To get the linking flags, invoke the
# following;
#
#   pkg-config --libs gtk4
# ======================================

# GNU options
# --------------------------------------

compiler_gnu=c:\msys64\mingw64\bin\g++.exe

compile_flags_gnu=-c \
				  -g \
				  -Wall

# Microsoft options
# --------------------------------------

compiler_ms=cl.exe

linker_ms=link.exe

# /EHsc : Disable exception handling. The MS C/C++ Compiler complains is this is not used.   
# /Fo   : Create an object file as output. 

compile_flags_ms=/c \
				 /EHsc \
				 /Fo

compile_flags_advanced_ms=$(compile_flags) \
						  /Wall

# Selection

compile_flags=$(compile_flags_gnu)


# ======================================
# Section 3)
# --------------------------------------
#
# Settings and flags associated with :
#
#   - Locations of Header files
#   - Locations of Library files
# --------------------------------------

dir_boost=c:\users\craig\boost_1_82_0


include_dirs_gnu=-I.\include \
				 -I$(dir_boost)

include_dirs_ms=/I..\include \
				/I$(dir_boost)

include_dirs=$(include_dirs_gnu)


# ----------------------------
# Locations of Library files
# ----------------------------

lib_boost_container_ms=c:\users\craig\boost_1_82_0\stage\x64\lib\libboost_container-vc143-mt-s-x64-1_82.lib
lib_boost_json_ms=c:\users\craig\boost_1_82_0\stage\x64\lib\libboost_json-vc143-mt-s-x64-1_82.lib


# ----------------------------
# Library files
# ----------------------------

lib_files_ms=$(lib_boost_container_ms) \
			 $(lib_boost_json_ms)

# Is the Gtk4 library file : c:\msys64\mingw64\bin\libgtk-4-1.dll

# ----------------------------
# Locations of Library files
# ----------------------------

libdir_c=c:\cygwin64\lib
libdir_gtk=c:\msys64\mingw64\lib
libdir_boost=c:\users\craig\boost_1_82_0\stage\x64\lib


# ======================================
# Section 5)
# --------------------------------------
#
# File lists
# ======================================

# vpath %.cpp src

JsonConfigReader_obj_files=Main.o \
						   Utilities.o \
						   OptionsStructs.o \
						   OptionsNetwork.o \
						   OptionsGeoRestriction.o \
						   OptionsPostProcessing.o \
						   CreateObjectOptions.o

link_flags_ms=$(lib_files_ms)

link_flags_advanced_ms=$(link_flags_ms)

UnionTest_obj_files=UnionTest.obj

NamespaceTest_obj_files=NamespaceTest.obj \
						Namespace_a.obj


# ======================================
# Section 6)
# --------------------------------------
#
# Targets
#
# ======================================
# With respect to the target;
#
#   InvokeBuilder-ms.exe
#
# Microsoft nmake is not powerful enough
# to be able to incorporate the
# following command into the target's
# rule;
#
#    pkgconfig --libs gtk4
# ======================================

compiler=$(compiler_gnu)


util=C:\Users\craig\Documents\GitHub\JsonConfigReader\src\Util.exe


all : JsonConfigReader.exe


# Suffix rule : .cpp -> .o
# ------------------------

%.o : %.cpp
	@echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "Target     : $@"
	@echo "Dependency : $<"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
	$(compiler) $(compile_flags) $(include_dirs) -o $@ $<
	@echo "----------------------------------------"

# .cpp.obj :
#     $(compiler) $(compile_flags) $(include_dirs) $*.cpp


JsonConfigReader.exe : $(JsonConfigReader_obj_files)
	$(linker_ms) -out:JsonConfigReader.exe $(JsonConfigReader_obj_files) $(link_flags_ms)


# invoke_pkgconfig :
#    $(pkgconfig) --libs gtk4


UnionTest.exe : $(UnionTest_obj_files)
	$(linker_ms) -out:UnionTest.exe $(UnionTest_obj_files)


NamespaceTest.exe : $(NamespaceTest_obj_files)
	$(linker_ms) -out:NamespaceTest.exe $(NamespaceTest_obj_files)


# test :
#     @echo ================================================================================
#     @echo Locations of build tools
#     @echo ------------------------
#     @echo -
#     @echo compiler = $(compiler)
#     @echo linker   = $(linker)
#     @echo -
#     @echo -
#     @echo Various flags
#     @echo -------------
#     @echo -
#     @echo compile_flags = $(compile_flags)
#     @echo -
#     @echo link_flags    = $(link_flags)
#     @echo -
#     @echo Example_1_obj_files = $(Example_1_obj_files)
#     @echo ================================================================================


# @ = Target
# < = First prerequisite of the target
# ^ = All prerequisites of the target
# ? = All prerequisites that are newer than the target

test : Utilities.cpp Main.cpp
	@echo $@ :
