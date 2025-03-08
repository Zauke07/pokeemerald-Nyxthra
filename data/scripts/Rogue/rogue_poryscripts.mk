
$(ROGUEPORYSCRIPTSDIR)/Strings/Rogue_Strings_Items.inc: $(ROGUEPORYSCRIPTSDIR)/Strings/Rogue_Strings_Items.pory
	$(PORYSCRIPT) -i $< -o $@ -cc tools/poryscript/command_config.json -fc tools/poryscript/font_config.json $(PORYSCRIPTARGS) 1_latin_rse_items

$(ROGUEPORYSCRIPTSDIR)/Generated/quests.inc: $(ROGUEPORYSCRIPTSDIR)/Generated/quests.pory
	$(PORYSCRIPT) -i $< -o $@ -cc tools/poryscript/command_config.json -fc tools/poryscript/font_config.json $(PORYSCRIPTARGS) 1_latin_rse_quest