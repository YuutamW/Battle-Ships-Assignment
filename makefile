# 1. Compiler and Flags
CXX      := g++
CXXFLAGS := -g 

# 2. Source Files
# Only list .cpp files here. 
# Note: Derived ships (Carrier, etc.) are header-only, so they are not listed.
SRCS     := main.cpp \
            Game.cpp \
            Grid.cpp \
            Player.cpp \
            HumanPlayer.cpp \
            AIPlayer.cpp \
            # Ship.cpp  <-- Uncomment this line ONLY if you created a Ship.cpp file

# 3. Object Directory and Files
OBJDIR   := obj
OBJS     := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS     := $(OBJS:.o=.d)

# 4. Executable Name
TARGET   := battleship_game

# --- Build Rules ---

# Default Target (runs when you type 'make')
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build successful! Run with ./$(TARGET)"

# Compile source files into object files
# Creates the 'obj' directory if it doesn't exist
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create the object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Include generated dependencies (so header updates trigger re-builds)
-include $(DEPS)

# Clean up
clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJDIR) $(TARGET)

# Phony targets
.PHONY: all clean