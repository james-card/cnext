MKDIR       := mkdir -p
SRC_DIR     := src
INCLUDE_DIR := include
FLAGS       := -rdynamic
REMOVE      := rm -rf
ARCHIVE     := ar rcs

OBJ_FILES := \
    $(OBJ_DIR)/Coroutines.o \
    $(OBJ_DIR)/DataTypes.o \
    $(OBJ_DIR)/Dictionary.o \
    $(OBJ_DIR)/DirectoryLib.o \
    $(OBJ_DIR)/Glibc27CompatLib.o \
    $(OBJ_DIR)/HashTable.o \
    $(OBJ_DIR)/List.o \
    $(OBJ_DIR)/LoggingLib.o \
    $(OBJ_DIR)/PosixCThreads.o \
    $(OBJ_DIR)/PosixProcesses.o \
    $(OBJ_DIR)/Queue.o \
    $(OBJ_DIR)/RandomLib.o \
    $(OBJ_DIR)/RedBlackTree.o \
    $(OBJ_DIR)/RsaLib.o \
    $(OBJ_DIR)/Scope.o \
    $(OBJ_DIR)/Sockets.o \
    $(OBJ_DIR)/SslCertificate.o \
    $(OBJ_DIR)/SslKey.o \
    $(OBJ_DIR)/Stack.o \
    $(OBJ_DIR)/StringLib.o \
    $(OBJ_DIR)/TimeUtils.o \
    $(OBJ_DIR)/Vector.o \
    $(OBJ_DIR)/WinCThreads.o \
    $(OBJ_DIR)/WinProcesses.o \
    $(OBJ_DIR)/ZipLib.o \
    $(OBJ_DIR)/miniz.o \

INCLUDES := \
    -Iinclude \

LINKS := \

WARNINGS := \
    -Wall \
    -Wextra \
    -Werror \

include defines.mk

all: $(OBJ_DIR)/Cnext.a

$(OBJ_DIR)/Cnext.a: $(OBJ_FILES) $(MAKEFILE) include.mk
	$(ARCHIVE) $(OBJ_DIR)/Cnext.a $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/%.h $(MAKEFILE) include.mk
	$(MKDIR) $(OBJ_DIR)
	$(CXX) $(FLAGS) $(INCLUDES) $(DEFINES) $(WARNINGS) -c $< -o $@

cleanall:
	$(REMOVE) $(BUILD_DIR)
