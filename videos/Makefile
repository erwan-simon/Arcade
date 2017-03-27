DIRS=		$(shell find . -type d -name 'ex*')
DISTNAME =	2_libraries

all:
	for d in $(DIRS); \
		do \
		$(MAKE) -C $$d ;\
		done


re:	fclean
	for d in $(DIRS); \
		do \
		$(MAKE) -C $$d ;\
		done


clean:
	for d in $(DIRS); \
		do \
		$(MAKE) -C $$d clean;\
		done


fclean:
	for d in $(DIRS); \
		do \
		$(MAKE) -C $$d fclean;\
		done
	/bin/rm -f $(DISTNAME).tar.gz


doc:
	for d in $(DIRS); \
		do \
		$(MAKE) -C $$d doc;\
		done

dist:	fclean
	tar -cvzf $(DISTNAME).tar.gz Makefile README $(DIRS)

################################################################################
