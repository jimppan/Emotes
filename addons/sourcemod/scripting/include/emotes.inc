#if defined _emotes_included
 #endinput
#endif
#define _emotes_included

#define EMOTES_PREFIX " \x09[\x04Emotes\x09]"
#define EMOTES_MAX_EMOTES_PER_PLAYER 1
#define EMOTES_KEY_LENGTH 65
#define EMOTES_FRAMES_TO_MOVE_EMOTE 100
#define EMOTE_SNAP_OFFSET 8
#define EMOTE_CONFIG "configs/emotes.cfg"

/**
 * Returns INVALID_ENT_REFERENCE (-1) if emote was not created, else it returns entity index of the sprite entity
 * @param client index
 * @param emote key (name of the emote)
 * @return int
 */
native int Emotes_SpawnEmote(int client, const char[] key);

/**
 * Gets the emote material path
 * @param emote key (name of the emote)
 * @param destination buffer
 * @param size of the buffer
 * @return void
 */
native void Emotes_GetEmoteMaterial(const char[] key, char[] dest, int len);

/**
 * Returns true if the key is an emote
 * @param emote key (name of the emote)
 * @return bool
 */
native bool Emotes_IsEmote(const char[] key);

/**
 * Called when a player spawns an emote by saying the key
 * @param client index
 * @param emote key (name of the emote)
 * @return Action (Plugin_Continue to spawn the emote, Plugin_Handled or Plugin_Stop to stop the emote from spawning)
 */
forward Action Emotes_OnEmoteSpawnSay(int client, char[] key);

public SharedPlugin __pl_emotes  =
{
	name = "emotes",
	file = "emotes.smx",
#if defined REQUIRE_PLUGIN
	required = 1
#else
	required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_emotes_SetNTVOptional()
{	
	MarkNativeAsOptional("Emotes_SpawnEmote");
	MarkNativeAsOptional("Emotes_GetEmoteMaterial");
}
#endif