include ../../make.inc
COMMAND = taumain.exe
COMMAND_OBJECTS = taumain.o
EXTER_LIB1  = ../glib.a
EXTER_SRC1  = ../*.f
EXTER_LIB2  = ../../glibk/glibk.a
EXTER_SRC2  = ../../glibk/GLK.f 
EXTER_LIB3  = ../../jetset/jetset.a
EXTER_SRC3  = ../../jetset/jetset74.f 
EXTER_LIB4  = ../../photos/glib.a
EXTER_SRC4  = ../../photos/photos.f
############
all:	$(COMMAND)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.f.o:
	$(F77) $(FFLAGS) -c $<
$(EXTER_LIB1): $(EXTER_SRC1)
	cd ..; make
$(EXTER_LIB2): $(EXTER_SRC2)
	cd ../../glibk; make
$(EXTER_LIB3): $(EXTER_SRC3)
	cd ../../jetset; make
$(EXTER_LIB4): $(EXTER_SRC4)
	cd ../../photos; make
# Link procedure
$(COMMAND): $(COMMAND_OBJECTS)  $(EXTER_LIB1)  $(EXTER_LIB2) $(EXTER_LIB3)  $(EXTER_LIB4)
	$(LD) -o $@ $(LDFLAGS) $(COMMAND_OBJECTS) $(EXTER_LIB1) $(EXTER_LIB2) $(EXTER_LIB3)  $(EXTER_LIB4) -lstdc++


#$(COMMAND): $(COMMAND_OBJECTS)  $(EXTER_LIB1) 
#	$(LD) -o $@ $(LDFLAGS) $(COMMAND_OBJECTS) $(EXTER_LIB1) 
clean:                                                     
	rm -f *.o; rm -f *.a; rm -f *~; rm -f *.exe
Clean:	clean
	cd prod; rm -f  *~ *.out *.ntup


run:
	@echo " this run will take some time:           "
	cd prod; sh go
	@echo " one may verify default results with:           "
	@echo " diff prod/tauola.babar   prod/tauola.output "
	@echo " or after extending generation to 20M events with:           "
	@echo " diff prod/tauola.babar.20Mevents prod/tauola.output "



