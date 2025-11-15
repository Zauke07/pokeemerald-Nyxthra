const struct Ability gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("Keine besondere Fähigkeit."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Gestank"),
        .description = COMPOUND_STRING("Hilft, wilde Pokémon fernzuhalten."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Niesel"),
        .description = COMPOUND_STRING("Ruft im Kampf Regen herbei."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Temposchub"),
        .description = COMPOUND_STRING("Erhöht Initiative nach und nach."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Kampfpanzer"),
        .description = COMPOUND_STRING("Wehrt Volltreffer ab."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Robustheit"),
        .description = COMPOUND_STRING("Schutz gegen 1-Treffer-K.O.-Attacken."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Feuchtigkeit"),
        .description = COMPOUND_STRING("Verhindert Explosion und Finale."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Flexibilität"),
        .description = COMPOUND_STRING("Verhindert Paralyse."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Sandschleier"),
        .description = COMPOUND_STRING("Erhöht Flucht im Sandsturm."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Statik"),
        .description = COMPOUND_STRING("Paralysiert bei Berührung."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Voltabsorber"),
        .description = COMPOUND_STRING("Wandelt Strom in KP um."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Wasserabsorption"),
        .description = COMPOUND_STRING("Wandelt Wasser in KP um."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Dösigkeit"),
        .description = COMPOUND_STRING("Schützt vor Anziehung."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Wolke Sieben"),
        .description = COMPOUND_STRING("Beseitigt Wettereinflüsse."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Facettenauge"),
        .description = COMPOUND_STRING("Erhöht die Genauigkeit."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .description = COMPOUND_STRING("Verhindert Einschlafen."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Farbwechsel"),
        .description = COMPOUND_STRING("Typ wird zur gegnerischen Att."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Immunität"),
        .description = COMPOUND_STRING("Verhindert Vergiftung."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Feuerfänger"),
        .description = COMPOUND_STRING("Wird bei Feuer stärker."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Puderabwehr"),
        .description = COMPOUND_STRING("Blockt Zusatzeff. von Att."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Tempomacher"),
        .description = COMPOUND_STRING("Verhindert Verwirrung."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Saugnapf"),
        .description = COMPOUND_STRING("Haftet fest am Boden."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Bedroher"),
        .description = COMPOUND_STRING("Senkt den Angriff des Gegners."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Wegsperre"),
        .description = COMPOUND_STRING("Verhindert die Flucht des Gegners."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Rauhaut"),
        .description = COMPOUND_STRING("Schadet bei Berührung."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Wunderwache"),
        .description = COMPOUND_STRING("Nur sehr effektive Attacken treffen."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Schwebe"),
        .description = COMPOUND_STRING("Immun gegen Boden-Att."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Sporenwahn"),
        .description = COMPOUND_STRING("Kann Status bei Berührung."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchro"),
        .description = COMPOUND_STRING("Gibt Status an Gegner."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Klarer Körper"),
        .description = COMPOUND_STRING("Keine Statussenkung."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Innere Kraft"),
        .description = COMPOUND_STRING("Heilt Status beim Tausch."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Blitzfänger"),
        .description = COMPOUND_STRING("Zieht Elektro an, stärkt Sp.-Angr."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Edelmut"),
        .description = COMPOUND_STRING("Fördert Zusatzeffekte."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Wassertempo"),
        .description = COMPOUND_STRING("Erhöht die Initiative bei Regen."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophyll"),
        .description = COMPOUND_STRING("Schneller bei Sonne."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Erleuchtung"),
        .description = COMPOUND_STRING("Erhöht Begegnungsrate."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Fährte"),
        .description = COMPOUND_STRING("Kopiert gegnerische Fähigkeit."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Kraftkoloss"),
        .description = COMPOUND_STRING("Verdoppelt den Angriffswert."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Giftdorn"),
        .description = COMPOUND_STRING("Paralysiert bei Berührung."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Felsenfest"),
        .description = COMPOUND_STRING("Erhöht Init. bei Zurückschr."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magmapanzer"),
        .description = COMPOUND_STRING("Verhindert Einfrieren."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Wasserschleier"),
        .description = COMPOUND_STRING("Verhindert Verbrennung."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnetfalle"),
        .description = COMPOUND_STRING("Blockiert Stahl-Flucht."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Lärmschutz"),
        .description = COMPOUND_STRING("Immun gegen Lärm-Att."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Regengenuss"),
        .description = COMPOUND_STRING("Heilt langsam bei Regen."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sandsturm"),
        .description = COMPOUND_STRING("Beschwört im Kampf einen Sandsturm."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Erzwinger"),
        .description = COMPOUND_STRING("Lässt Gegner mehr AP verbrauchen."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Speckschicht"),
        .description = COMPOUND_STRING("Resistent gg. Feuer/Eis."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Frühwecker"),
        .description = COMPOUND_STRING("Erwacht schnell aus dem Schlaf."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Flammkörper"),
        .description = COMPOUND_STRING("Verbrennt bei Berührung."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Reißaus"),
        .description = COMPOUND_STRING("Ermöglicht sichere Flucht."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Adlerauge"),
        .description = COMPOUND_STRING("Verhindert Genauigk.-Senken."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Scherenmacht"),
        .description = COMPOUND_STRING("Verhindert das Senken des Angriffs."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Mitnahme"),
        .description = COMPOUND_STRING("Kann nach dem Kampf Items aufheben."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Faulenz"),
        .description = COMPOUND_STRING("Attackiert nur jede zweite Runde."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Übereifer"),
        .description = COMPOUND_STRING("Erhöht Angr., senkt Gen."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Charmebolzen"),
        .description = COMPOUND_STRING("Anziehung bei Berührung."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Mehr Sp.-Angr. mit Minus."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Minus"),
        .description = COMPOUND_STRING("Mehr Sp.-Angr. mit Plus."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Prognose"),
        .description = COMPOUND_STRING("Formeo ändert sich mit dem Wetter."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Klebrigkeit"),
        .description = COMPOUND_STRING("Schützt Items vor Diebstahl."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Exoskelett"),
        .description = COMPOUND_STRING("Kann Statusprobleme selbst heilen."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Adrenalin"),
        .description = COMPOUND_STRING("Stärker bei Status."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Notschutz"),
        .description = COMPOUND_STRING("Mehr Vert. bei Status."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Flüssigkeit"),
        .description = COMPOUND_STRING("Schadet bei Saug-Att."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Notdünger"),
        .description = COMPOUND_STRING("Stärkt Pflanz.-Att. in Not."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Großbrand"),
        .description = COMPOUND_STRING("Stärkt Feuer-Att. in Not."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Sturzbach"),
        .description = COMPOUND_STRING("Stärkt Wasser-Att. in Not."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Hexaplaga"),
        .description = COMPOUND_STRING("Stärkt Käfer-Att. in Not."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Steinhaupt"),
        .description = COMPOUND_STRING("Schadet nicht bei Rückstoß."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Dürre"),
        .description = COMPOUND_STRING("Macht das Sonnenlicht grell."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Bodengewalt"),
        .description = COMPOUND_STRING("Blockiert Flucht (außer Flug)."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Munterkeit"),
        .description = COMPOUND_STRING("Verhindert Einschlafen."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("Qualm"),
        .description = COMPOUND_STRING("Verhindert das Senken der Statuswerte."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Reine Kraft"),
        .description = COMPOUND_STRING("Verdoppelt den Angriffswert."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Panzerhaut"),
        .description = COMPOUND_STRING("Wehrt Volltreffer ab."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Luftschleuse"),
        .description = COMPOUND_STRING("Beseitigt Wettereinflüsse."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Wirrfüße"),
        .description = COMPOUND_STRING("Mehr Ausweichen verwirrt."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motorisierung"),
        .description = COMPOUND_STRING("Schneller nach Elektro-Treff."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalität"),
        .description = COMPOUND_STRING("Mehr Schaden bei gleichem Geschl."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Feste Klaue"),
        .description = COMPOUND_STRING("Erhöht Initiative bei Zurückschrecken."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Schneemantel"),
        .description = COMPOUND_STRING("Erhöht die Ausweichrate bei Hagel."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Völlerei"),
        .description = COMPOUND_STRING("Verzehrt Beeren früher als üblich."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Zornesstimme"),
        .description = COMPOUND_STRING("Max. Angr. nach Volltreffer."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Entlastung"),
        .description = COMPOUND_STRING("Erhöht Init. nach Itemverbrauch."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Hitzeschutz"),
        .description = COMPOUND_STRING("Halbiert Feuerschaden."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simpel"),
        .description = COMPOUND_STRING("Verdoppelt alle Statusänderungen."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Trockenheit"),
        .description = COMPOUND_STRING("Schadet Sonne, heilt Wasser."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Download"),
        .description = COMPOUND_STRING("Passt Angr. an Gegner an."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Eisenfaust"),
        .description = COMPOUND_STRING("Stärkt Schlag-Attacken."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Giftheilung"),
        .description = COMPOUND_STRING("Heilt bei Gift."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Anpassung"),
        .description = COMPOUND_STRING("Stärkt Attacken gleichen Typs."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Techniker"),
        .description = COMPOUND_STRING("Stärkt schwache Attacken."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydration"),
        .description = COMPOUND_STRING("Heilt Statusprobleme bei Regen."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Solarkraft"),
        .description = COMPOUND_STRING("Mehr Sp.-Angr., verliert KP."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Rasanz"),
        .description = COMPOUND_STRING("Init. erhöht bei Status."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalisierung"),
        .description = COMPOUND_STRING("Alle Att. werden Normal."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Scharfschütze"),
        .description = COMPOUND_STRING("Stärkere Volltreffer."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Magieschild"),
        .description = COMPOUND_STRING("Kein Effekt-Schaden."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("Schildlos"),
        .description = COMPOUND_STRING("Treffer garantiert."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Hinterhalt"),
        .description = COMPOUND_STRING("Greift immer zuletzt an."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Techniker"),
        .description = COMPOUND_STRING("Stärkt schwache Attacken."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Floraschutz"),
        .description = COMPOUND_STRING("Schützt vor Status bei Sonne."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Tollpatsch"),
        .description = COMPOUND_STRING("Kann keine Items nutzen."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Überbrückung"),
        .description = COMPOUND_STRING("Ignoriert gegner. Fähigkeit."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Glückspilz"),
        .description = COMPOUND_STRING("Erhöht die kritische Trefferquote."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Finalschlag"),
        .description = COMPOUND_STRING("Schadet bei K.O."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Vorahnung"),
        .description = COMPOUND_STRING("Warnt vor starken Att."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Vorwarnung"),
        .description = COMPOUND_STRING("Zeigt stärkste Attacke."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Ignoranz"),
        .description = COMPOUND_STRING("Ignoriert Statusänderungen des Gegners."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Färberlinse"),
        .description = COMPOUND_STRING("Verstärkt “nicht sehr effektive” Attacken."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filter"),
        .description = COMPOUND_STRING("Reduziert starken Schaden."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Saumselig"),
        .description = COMPOUND_STRING("Angr. und Init. halbiert."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Rauflust"),
        .description = COMPOUND_STRING("Norm./Kampf trifft Geist."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Sturmsog"),
        .description = COMPOUND_STRING("Zieht Wasser an, Sp.-Angr.+"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Eiskörper"),
        .description = COMPOUND_STRING("Heilt KP bei Hagel."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Felskern"),
        .description = COMPOUND_STRING("Reduziert starken Schaden."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Hagelalarm"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Beschwört im Kampf Hagel."),
    #else
        .description = COMPOUND_STRING("Beschwört im Kampf Hagel."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Honigmaul"),
        .description = COMPOUND_STRING("Sammelt nach dem Kampf Honig."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Schnüffler"),
        .description = COMPOUND_STRING("Überprüft das getragene Item des Gegners."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Achtlos"),
        .description = COMPOUND_STRING("Verstärkt Attacken mit Rückstoßschaden."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Variabilität"),
        .description = COMPOUND_STRING("Ändert Typ je nach getragener Tafel."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Blütenhülle"),
        .description = COMPOUND_STRING("Angr./Sp.Vert.+ bei Sonne."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Alptraum"),
        .description = COMPOUND_STRING("Reduziert die KP eines schlafenden Gegners."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Taschendieb"),
        .description = COMPOUND_STRING("Stiehlt ein Item, wenn es getroffen wird."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Rohe Gewalt"),
        .description = COMPOUND_STRING("Kein Effekt, mehr Schaden."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Umkehrung"),
        .description = COMPOUND_STRING("Statusänderungen haben den gegenteiligen Effekt."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Anspannung"),
        .description = COMPOUND_STRING("Gegner kann keine Beeren."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Trotz"),
        .description = COMPOUND_STRING("Angr.+ bei Statsenkung."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Schwächling"),
        .description = COMPOUND_STRING("Gibt bei halben KP auf."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Fluchkörper"),
        .description = COMPOUND_STRING("Kann eine Attacke des Gegners deaktivieren."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Heilherz"),
        .description = COMPOUND_STRING("Kann Statusprobleme eines Verbündeten heilen."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Freundeskreis"),
        .description = COMPOUND_STRING("Reduziert Schaden an Verbündeten."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Bruchrüstung"),
        .description = COMPOUND_STRING("Vert.-, Init.+ bei phys. Treff."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Schwermetall"),
        .description = COMPOUND_STRING("Verdoppelt das Gewicht."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Leichtmetall"),
        .description = COMPOUND_STRING("Halbiert das Gewicht."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multischuppe"),
        .description = COMPOUND_STRING("Reduziert Schaden, wenn KP voll sind."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Gift-Boost"),
        .description = COMPOUND_STRING("Verstärkt physische Angriffe bei Vergiftung."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Hitzesturm"),
        .description = COMPOUND_STRING("Verstärkt Spezial-Angriffe bei Verbrennung."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Ernte"),
        .description = COMPOUND_STRING("Kann eine verbrauchte Beere wiederherstellen."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Telepathie"),
        .description = COMPOUND_STRING("Weicht Attacken von Verbündeten aus."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Unberechenbar"),
        .description = COMPOUND_STRING("Erhöht einen Wert, senkt einen anderen."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Wetterschutz"),
        .description = COMPOUND_STRING("Schützt vor Wetterschaden."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Gifthauch"),
        .description = COMPOUND_STRING("Kann bei Kontakt vergiften."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Beleber"),
        .description = COMPOUND_STRING("Stellt beim Auswechseln KP wieder her."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Riesenbauch"),
        .description = COMPOUND_STRING("Schützt vor Senkung der Vert.."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sandschwall"),
        .description = COMPOUND_STRING("Erhöht die Initiative bei Sandsturm."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Wunderhaut"),
        .description = COMPOUND_STRING("Status-Attacken eher fehl."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analyse"),
        .description = COMPOUND_STRING("Mehr Schaden bei spätem Zug."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Illusion"),
        .description = COMPOUND_STRING("Tritt als letztes in Kampf."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Wandler"),
        .description = COMPOUND_STRING("Wird zum Gegner."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Tarnung"),
        .description = COMPOUND_STRING("Ignoriert Schilde."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Mumie"),
        .description = COMPOUND_STRING("Überträgt Fähigkeit bei Hit."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Siegeswille"),
        .description = COMPOUND_STRING("Erhöht den Angriff nach einem K.O."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Redlichkeit"),
        .description = COMPOUND_STRING("Angr.+ bei Unlicht-Treffer."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Angsthase"),
        .description = COMPOUND_STRING("Ermöglicht sichere Flucht."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Magiespiegel"),
        .description = COMPOUND_STRING("Spiegelt Statusattacken."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Vegetarier"),
        .description = COMPOUND_STRING("Angr.+ bei Pflanzentreffer."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Strolch"),
        .description = COMPOUND_STRING("Status-Attacken Priorität."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Sandgewalt"),
        .description = COMPOUND_STRING("Verstärkt Att. bei Sandsturm."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Eisenstachel"),
        .description = COMPOUND_STRING("Schadet bei Berührung."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Zen-Modus"),
        .description = COMPOUND_STRING("Verwandelt sich bei halben KP."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Triumphstern"),
        .description = COMPOUND_STRING("Genauigkeit für Team +."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turbobrand"),
        .description = COMPOUND_STRING("Ignoriert gegner. Fähigkeiten."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravolt"),
        .description = COMPOUND_STRING("Ignoriert gegner. Fähigkeiten."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Aromaschleier"),
        .description = COMPOUND_STRING("Schützt vor Zugzwang."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Blütenhülle"),
        .description = COMPOUND_STRING("Schützt Pflanzen-Teamwerte."),
        .aiRating = 0,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Backentasche"),
        .description = COMPOUND_STRING("Mehr KP bei Beerennutzung."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Wandlungskunst"),
        .description = COMPOUND_STRING("Typ wird zuletzt genutzte Att."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Pelzmantel"),
        .description = COMPOUND_STRING("Halbiert physischen Schaden."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Zauberer"),
        .description = COMPOUND_STRING("Stiehlt Item bei Treffer."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Kugelsicher"),
        .description = COMPOUND_STRING("Schützt vor Ball/Bomben."),
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Wetteifer"),
        .description = COMPOUND_STRING("Sp.-Angr.+ bei Statsenkung."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Eiserner Kiefer"),
        .description = COMPOUND_STRING("Verstärkt Beißattacken."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Frostschicht"),
        .description = COMPOUND_STRING("Normal wird zu Eis-Att."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Zuckerschleier"),
        .description = COMPOUND_STRING("Verhindert Einschlafen."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Taktikwechsel"),
        .description = COMPOUND_STRING("Formwechsel je nach Att."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("Orkanschwingen"),
        .description = COMPOUND_STRING("Flug-Attacken Priorität."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Megawumme"),
        .description = COMPOUND_STRING("Verstärkt Aura/Puls-Att."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Graspelz"),
        .description = COMPOUND_STRING("Vert.+ im Grasfeld."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Symbiose"),
        .description = COMPOUND_STRING("Gibt Item bei Verbrauch."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Krallenwucht"),
        .description = COMPOUND_STRING("Verstärkt Kontakt-Att."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Feenschicht"),
        .description = COMPOUND_STRING("Normal wird zu Feen-Att."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Zähes Netz"),
        .description = COMPOUND_STRING("Init.- bei Berührung."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Flugblatt"),
        .description = COMPOUND_STRING("Normal wird zu Flug-Att."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Elternliebe"),
        .description = COMPOUND_STRING("Greift zweimal an."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Dunkelaura"),
        .description = COMPOUND_STRING("Stärkt Unlicht-Attacken."),
        .aiRating = 6,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Feenaura"),
        .description = COMPOUND_STRING("Stärkt Feen-Attacken."),
        .aiRating = 6,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Auraschleier"),
        .description = COMPOUND_STRING("Schwächt Unlicht/Feen-Att."),
        .aiRating = 3,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Urmeer"),
        .description = COMPOUND_STRING("Lässt es stark regnen."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Urzeit-Land"),
        .description = COMPOUND_STRING("Macht Sonne extrem grell."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta-Sturm"),
        .description = COMPOUND_STRING("Erzeugt starke Winde."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Ausdauer"),
        .description = COMPOUND_STRING("Vert.+ bei Treffer."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("Feigling"),
        .description = COMPOUND_STRING("Flieht bei halben KP."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("Notausgang"),
        .description = COMPOUND_STRING("Flieht bei halben KP."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("Wasserdichte"),
        .description = COMPOUND_STRING("Vert.++ bei Wassertreffer."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Gnadenlos"),
        .description = COMPOUND_STRING("Immer Volltreffer bei Gift."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("Schildlos"),
        .description = COMPOUND_STRING("Treffer garantiert."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Verfolgung"),
        .description = COMPOUND_STRING("Doppelter Schaden bei Einwechseln."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Blubb-Blubb"),
        .description = COMPOUND_STRING("0,5x Feuerschaden, 2x Wasser, kein Brand."),
        .aiRating = 8,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Stahlarbeiter"),
        .description = COMPOUND_STRING("Verstärkt Stahl-Attacken."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Berserker"),
        .description = COMPOUND_STRING("Erhöht den Sp-Angr. bei niedrigen KP."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Schneeschwall"),
        .description = COMPOUND_STRING("Init.+ bei Hagel."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Langstrecker"),
        .description = COMPOUND_STRING("Attackiert ohne Kontakt."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Flüssigstimme"),
        .description = COMPOUND_STRING("Sound wird zu Wasser-Att."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triage"),
        .description = COMPOUND_STRING("Heil-Attacken Priorität."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanisierung"),
        .description = COMPOUND_STRING("Normal wird zu Elektro-Att."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Wellenreiter"),
        .description = COMPOUND_STRING("Init.x2 bei Elektrofeld."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Schwarmtaktik"),
        .description = COMPOUND_STRING("Wechselt in Schulform."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("Verkleidung"),
        .description = COMPOUND_STRING("Vermeidet 1 Runde Schaden."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Bund der Besten"),
        .description = COMPOUND_STRING("Wird zu Ash-Greninja nach K.O."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("Power-Konstrukt"),
        .description = COMPOUND_STRING("Zellen helfen, wenn es geschwächt ist."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Korrosion"),
        .description = COMPOUND_STRING("Kann Stahl/Gift vergiften."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Komatös"),
        .description = COMPOUND_STRING("Immer Schlaf, kann angreifen."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Königliche Würde"),
        .description = COMPOUND_STRING("Blockiert Prioritätszüge."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Nachschlag"),
        .description = COMPOUND_STRING("Schaden bei K.O."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Tänzer"),
        .description = COMPOUND_STRING("Kopiert Tanzattacken."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Batterie"),
        .description = COMPOUND_STRING("Sp.-Angr.+ für Team."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Flauschig"),
        .description = COMPOUND_STRING("Halbiert Kontakt-Schaden, verdoppelt Feuer-Schaden."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Blendung"),
        .description = COMPOUND_STRING("Schützt vor Prioritäts-Att."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Seelenherz"),
        .description = COMPOUND_STRING("Sp.-Angr.+ bei K.O."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Verfilztes Haar"),
        .description = COMPOUND_STRING("Init.- bei Berührung."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receiver"),
        .description = COMPOUND_STRING("Erbt Fähigkeit Verbündeter."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Alchemie"),
        .description = COMPOUND_STRING("Kopiert Fähigkeit Verbündeter."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Bestien-Boost"),
        .description = COMPOUND_STRING("Höchsten Wert + bei K.O."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("Alpha-System"),
        .description = COMPOUND_STRING("Typ je nach Item."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("Elektro-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Elektrofeld."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Psycho-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Psychofeld."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Nebel-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Nebelfeld."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Gras-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Grasfeld."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Vollmetallkörper"),
        .description = COMPOUND_STRING("Verhindert Statsenkung."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Schattenhülle"),
        .description = COMPOUND_STRING("Weniger Schaden bei vollen KP."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Prisma-Rüstung"),
        .description = COMPOUND_STRING("Weniger Schaden bei Schwächen."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neurokraft"),
        .description = COMPOUND_STRING("Stärkt sehr effektive Att."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Kühnes Schwert"),
        .description = COMPOUND_STRING("Angriff erhöht beim Kampfeintritt."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Unb. Schild"),
        .description = COMPOUND_STRING("Vert. erhöht beim Eintritt."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("Libero"),
        .description = COMPOUND_STRING("Typ wird zu letzter Att."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Ball-Abholung"),
        .description = COMPOUND_STRING("Holt fehlgeworfene Bälle."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Flauschfeder"),
        .description = COMPOUND_STRING("Senkt Init. bei Treffer."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Prop.Schwanz"),
        .description = COMPOUND_STRING("Ignoriert Zug-Anziehung."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Spiegelrüstung"),
        .description = COMPOUND_STRING("Reflektiert Statsenkung."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Schluckgeschosse"),
        .description = COMPOUND_STRING("Kehrt mit Beute nach Surfer/Taucher zurück."),
        .aiRating = 3,
        .cantBeCopied = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Sturmkraft"),
        .description = COMPOUND_STRING("Ignoriert Zug-Anziehung."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Dampfmaschine"),
        .description = COMPOUND_STRING("Init.++ bei Feuer/Wasser."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk-Rock"),
        .description = COMPOUND_STRING("Sound-Att. stärker/halbiert Schaden."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Sandstrahl"),
        .description = COMPOUND_STRING("Löst Sandsturm bei Treffer aus."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Eisschuppen"),
        .description = COMPOUND_STRING("Halbiert Spezial-Schaden."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Reifeprozess"),
        .description = COMPOUND_STRING("Verdoppelt Beereneffekt."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Eisgesicht"),
        .description = COMPOUND_STRING("Blockt einmal physisch."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Kraftzentrum"),
        .description = COMPOUND_STRING("Verstärkt Team-Attacken."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimikry"),
        .description = COMPOUND_STRING("Ändert Typ nach Terrain."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Screen Reiniger"),
        .description = COMPOUND_STRING("Hebt Schilde auf."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Stahlgeist"),
        .description = COMPOUND_STRING("Stahl-Att. Team verstärkt."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Verderbenskörper"),
        .description = COMPOUND_STRING("K.O. nach 3 Runden bei Kontakt."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Wandergeist"),
        .description = COMPOUND_STRING("Tauscht Fähigkeit bei Kontakt."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Gorilla-Taktik"),
        .description = COMPOUND_STRING("Angr.+, nur erste Att. nutzbar."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Neutral-Gas"),
        .description = COMPOUND_STRING("Deaktiviert alle Fähigkeiten."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Pastellschleier"),
        .description = COMPOUND_STRING("Verhindert Gift für Team."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Hungerwechsel"),
        .description = COMPOUND_STRING("Wechselt Form jede Runde."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Flinkzug"),
        .description = COMPOUND_STRING("Manchmal zuerst."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Unsichtbar Faust"),
        .description = COMPOUND_STRING("Kontakt trifft durch Schutz."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Wundermedizin"),
        .description = COMPOUND_STRING("Setzt Stats beim Eintritt zurück."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Elektro-Attacken stärker."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Drachenschlund"),
        .description = COMPOUND_STRING("Drachen-Attacken stärker."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Schreckensruf"),
        .description = COMPOUND_STRING("Angr.+ nach K.O."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Schreckensmähne"),
        .description = COMPOUND_STRING("Sp.-Angr.+ nach K.O."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("Als Eins"),
        .description = COMPOUND_STRING("Effekt von Anspannung+Schreckensmähne."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("Als Eins"),
        .description = COMPOUND_STRING("Effekt von Anspannung+Schreckensmähne."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("VerweilenderDuft"),
        .description = COMPOUND_STRING("Gegner erhält diese Fähigkeit."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("Samen-Erzeuger"),
        .description = COMPOUND_STRING("Grasfeld bei Treffer."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("Wärmetausch"),
        .description = COMPOUND_STRING("Angr.+ bei Feuer, immun gegen Brand."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("Wutschale"),
        .description = COMPOUND_STRING("Wird bei halben KP wütend"),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("Reinigungssalz"),
        .description = COMPOUND_STRING("Schützt vor Status, 0,5x Geistschaden."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("Gut gebacken"),
        .description = COMPOUND_STRING("Durch Feuer gestärkt"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Windreiter"),
        .description = COMPOUND_STRING("Kein Windschaden, Angr.+ bei Wind."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Wachhund"),
        .description = COMPOUND_STRING("Angr.+ bei Einschüchterung, kein Zwangswechsel."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Felsenträger"),
        .description = COMPOUND_STRING("Gesteins-Attacken stärker."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Windkraft"),
        .description = COMPOUND_STRING("Elektro-Att. erhöht bei Windtreffer."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("Von Null zu Held"),
        .description = COMPOUND_STRING("Formwechsel beim Wechsel."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Kommandant"),
        .description = COMPOUND_STRING("Springt in Dondozo bei Anwesenheit."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Elektromorphose"),
        .description = COMPOUND_STRING("Elektro-Att. erhöht bei Treffer."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Protosynthese"),
        .description = COMPOUND_STRING("Höchster Wert erhöht bei Sonne oder Booster."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Quantenantrieb"),
        .description = COMPOUND_STRING("Höchster Wert erhöht bei Elektrofeld oder Booster."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Gold-Schild"),
        .description = COMPOUND_STRING("Immun gegen Status-Att."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Schatz Verderb"),
        .description = COMPOUND_STRING("Senkt den Sp.-Angr. der Gegner."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Schwert Verderb"),
        .description = COMPOUND_STRING("Senkt die Vert. aller anderen."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Tafeln Verderb"),
        .description = COMPOUND_STRING("Senkt den Angr. aller anderen."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Perlen Verderb"),
        .description = COMPOUND_STRING("Senkt die Sp.-Vert. aller anderen."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Orichalkum-Puls"),
        .description = COMPOUND_STRING("Sonne grell, Angr. erhöht aktiv."),
        .aiRating = 8,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Hadronen-Motor"),
        .description = COMPOUND_STRING("Elektrofeld aktiv, Sp.-Angr. erhöht."),
        .aiRating = 8,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Opportunist"),
        .description = COMPOUND_STRING("Kopiert Statserhöhungen."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Wiederkäuen"),
        .description = COMPOUND_STRING("Kann Beere zweimal essen."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Schärfe"),
        .description = COMPOUND_STRING("Schneid-Att. stärker."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Oberherr"),
        .description = COMPOUND_STRING("Angr./Sp.-Angr. erhöht je K.O.-Team."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Co-Star"),
        .description = COMPOUND_STRING("Kopiert Team-Stats bei Eintritt."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Giftiger Schutt"),
        .description = COMPOUND_STRING("Giftspitzen bei physischem Schaden."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Panzerschwanz"),
        .description = COMPOUND_STRING("Blockiert Prioritätszüge."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Erdesser"),
        .description = COMPOUND_STRING("Heilt KP bei Boden-Treffer."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("Myzel-Kraft"),
        .description = COMPOUND_STRING("Status-Att. zuletzt, ignoriert Fähigkeiten."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("Gastfreundschaft"),
        .description = COMPOUND_STRING("Heilt KP eines Verbündeten beim Eintritt."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("Geistiges Auge"),
        .description = COMPOUND_STRING("Norm./Kampf trifft Geist, ignoriert Ausweichen."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("Aspekt-Teal"),
        .description = COMPOUND_STRING("Erhöht Werte je nach Iki-Form."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("Aspekt-Glut"),
        .description = COMPOUND_STRING("Erhöht Werte je nach Iki-Form."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("Aspekt-Quelle"),
        .description = COMPOUND_STRING("Erhöht Werte je nach Iki-Form."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("Aspekt-Eckpfeil"),
        .description = COMPOUND_STRING("Erhöht Werte je nach Iki-Form."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("Giftkette"),
        .description = COMPOUND_STRING("Kann starke Vergiftung auslösen."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("Supersüßer Sirup"),
        .description = COMPOUND_STRING("Senkt gegnerische Ausweichquote beim Eintritt."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera-Wandel"),
        .description = COMPOUND_STRING("Wechselt in Tera-Form."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Tera-Panzer"),
        .description = COMPOUND_STRING("Bei vollen KP nicht sehr effektiv."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Terra-Null"),
        .description = COMPOUND_STRING("Hebt Wetter und Terrain auf."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Gift-Puppe"),
        .description = COMPOUND_STRING("Vergiftete Gegner werden verwirrt."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
