#pragma once

struct XZoneInfo
{
	const char* name;
	int type1;
	int type2;
};

typedef enum assetType_e
{
    ASSET_TYPE_XMODELPIECES = 0x0,
    ASSET_TYPE_PHYSPRESET = 0x1,
    ASSET_TYPE_XANIMPARTS = 0x2,
    ASSET_TYPE_XMODEL = 0x3,
    ASSET_TYPE_MATERIAL = 0x4,
    ASSET_TYPE_PIXELSHADER = 0x5,
    ASSET_TYPE_TECHNIQUE_SET = 0x6,
    ASSET_TYPE_IMAGE = 0x7,
    ASSET_TYPE_SOUND = 0x8,
    ASSET_TYPE_SOUND_CURVE = 0x9,
    ASSET_TYPE_CLIPMAP = 0xA,
    ASSET_TYPE_CLIPMAP_PVS = 0xB,
    ASSET_TYPE_COMWORLD = 0xC,
    ASSET_TYPE_GAMEWORLD_SP = 0xD,
    ASSET_TYPE_GAMEWORLD_MP = 0xE,
    ASSET_TYPE_MAP_ENTS = 0xF,
    ASSET_TYPE_GFXWORLD = 0x10,
    ASSET_TYPE_LIGHT_DEF = 0x11,
    ASSET_TYPE_UI_MAP = 0x12,
    ASSET_TYPE_FONT = 0x13,
    ASSET_TYPE_MENULIST = 0x14,
    ASSET_TYPE_MENU = 0x15,
    ASSET_TYPE_LOCALIZE_ENTRY = 0x16,
    ASSET_TYPE_WEAPON = 0x17,
    ASSET_TYPE_SNDDRIVER_GLOBALS = 0x18,
    ASSET_TYPE_FX = 0x19,
    ASSET_TYPE_IMPACT_FX = 0x1A,
    ASSET_TYPE_AITYPE = 0x1B,
    ASSET_TYPE_MPTYPE = 0x1C,
    ASSET_TYPE_CHARACTER = 0x1D,
    ASSET_TYPE_XMODELALIAS = 0x1E,
    ASSET_TYPE_RAWFILE = 0x1F,
    ASSET_TYPE_STRINGTABLE = 0x20,
    ASSET_TYPE_COUNT = 0x21,
    ASSET_TYPE_STRING = 0x21,
    ASSET_TYPE_ASSETLIST = 0x22
} assetType_t;

struct GfxImage
{
    char* texture;
    char unknown2;
    char a3;
    char a2;
    char unknown3;
    char unknown4;
    char unknown5;
    char unknown6;
    char a4;
    int dataLength1;
    int dataLength2;
    short height;
    short width;
    short depth;
    short unknown8;
    char* name;
};

typedef float vec4_t[4];

struct MaterialConstantDef 
{
    int nameHash;
    char name[12];
    vec4_t literal;
};
 
struct GfxStateBits 
{
#ifdef XBOX
    int loadBits[2];
#elif defined PS3
    int (*loadBits)[2];
 #ifdef MW2 || MW3
    int unknown;
 #endif
#endif
};
 
struct WaterWritable
{
    float floatTime;
};
 
struct water_t 
{
    WaterWritable writable;
    float *H0X;     // Count = M * N
    float *H0Y;     // Count = M * N
    float *wTerm;       // Count = M * N
    int M;
    int N;
    float Lx;
    float Lz;
    float gravity;
    float windvel;
    float winddir[2];
    float amplitude;
    float codeConstant[4];
    GfxImage *image;
};
 
/* MaterialTextureDef->semantic */
#define TS_2D       0x0
#define TS_FUNCTION 0x1
#define TS_COLOR_MAP    0x2
#define TS_UNUSED_1 0x3
#define TS_UNUSED_2 0x4
#define TS_NORMAL_MAP   0x5
#define TS_UNUSED_3 0x6
#define TS_UNUSED_4 0x7
#define TS_SPECULAR_MAP 0x8
#define TS_UNUSED_5 0x9
#define TS_UNUSED_6 0xA
#define TS_WATER_MAP    0xB
 
union MaterialTextureDefInfo 
{
    GfxImage *image;    // MaterialTextureDef->semantic != TS_WATER_MAP
    water_t *water;     // MaterialTextureDef->semantic == TS_WATER_MAP
};
 
struct MaterialTextureDef
{
  unsigned int typeHash; // asset hash of type
  char firstCharacter; // first character of image name
  char secondLastCharacter; // second-last character of image name (maybe only in CoD4?!)
  unsigned char unknown; // maybe 0xE2
  char unknown2; // likely 0x00
  GfxImage* image; // GfxImage* actually
};
 
union GFxDrawSurfFields
{
    unsigned long long unused,
            primarySortKey,
            surfType,
            primaryLightIndex,
            prepass,
            materialSortedIndex,
            customIndex,
            reflectionProbeIndex,
            objectId;
};
 
union GfxDrawSurf 
{
    GFxDrawSurfFields fields;
    unsigned long long packed;
};


enum MaterialTechniqueType
{
  TECHNIQUE_DEPTH_PREPASS = 0x0,
  TECHNIQUE_BUILD_FLOAT_Z = 0x1,
  TECHNIQUE_BUILD_SHADOWMAP_DEPTH = 0x2,
  TECHNIQUE_BUILD_SHADOWMAP_COLOR = 0x3,
  TECHNIQUE_UNLIT = 0x4,
  TECHNIQUE_EMISSIVE = 0x5,
  TECHNIQUE_EMISSIVE_SHADOW = 0x6,
  TECHNIQUE_LIT_BEGIN = 0x7,
  TECHNIQUE_LIT = 0x7,
  TECHNIQUE_LIT_SUN = 0x8,
  TECHNIQUE_LIT_SUN_SHADOW = 0x9,
  TECHNIQUE_LIT_SPOT = 0xA,
  TECHNIQUE_LIT_SPOT_SHADOW = 0xB,
  TECHNIQUE_LIT_OMNI = 0xC,
  TECHNIQUE_LIT_OMNI_SHADOW = 0xD,
  TECHNIQUE_LIT_END = 0xE,
  TECHNIQUE_LIGHT_SPOT = 0xE,
  TECHNIQUE_LIGHT_OMNI = 0xF,
  TECHNIQUE_LIGHT_SPOT_SHADOW = 0x10,
  TECHNIQUE_FAKELIGHT_NORMAL = 0x11,
  TECHNIQUE_FAKELIGHT_VIEW = 0x12,
  TECHNIQUE_SUNLIGHT_PREVIEW = 0x13,
  TECHNIQUE_CASE_TEXTURE = 0x14,
  TECHNIQUE_WIREFRAME_SOLID = 0x15,
  TECHNIQUE_WIREFRAME_SHADED = 0x16,
  TECHNIQUE_SHADOWCOOKIE_CASTER = 0x17,
  TECHNIQUE_SHADOWCOOKIE_RECEIVER = 0x18,
  TECHNIQUE_DEBUG_BUMPMAP = 0x19,
  TECHNIQUE_COUNT = 0x1A,
  TECHNIQUE_TOTAL_COUNT = 0x1B,
  TECHNIQUE_NONE = 0x1C,
};

struct VertexDecl
{
        const char* name;
        int unknown;
        char pad[28];
        IDirect3DVertexDeclaration9* declarations[16];
};

struct PixelShader
{
        const char* name;
        IDirect3DPixelShader9* shader;
        DWORD* bytecode;
        int flags;
};

struct VertexShader
{
        const char* name;
        IDirect3DVertexShader9* shader;
        DWORD* bytecode;
        int flags;
};

struct MaterialPass
{
        VertexDecl* vertexDecl;
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        char pad[8];
};

struct MaterialTechnique
{
        int pad;
        short pad2;
        short numPasses;
        MaterialPass passes[1];
};

struct MaterialTechniqueSet
{
        const char* name;
        char pad[4];
        MaterialTechniqueSet* remappedTechniqueSet;
        MaterialTechnique* techniques[48];
};

typedef struct
{
	int type;
	int id;
	void* extraData;
} menuExpToken_t;

typedef struct
{
	int count;
	menuExpToken_t* tokens;
} menuExpression_t;

enum netadrtype_t
{
  NA_BOT = 0x0,
  NA_BAD = 0x1,
  NA_LOOPBACK = 0x2,
  NA_BROADCAST = 0x3,
  NA_IP = 0x4,
};

#pragma pack(push, 4)
struct netadr_t
{
  netadrtype_t type;
  char ip[4];
  unsigned __int16 port;
};
#pragma pack(pop)

typedef enum {
	NS_CLIENT,
	NS_SERVER
} netsrc_t;

enum connstate_t
{
  CA_DISCONNECTED = 0x0,
  CA_CINEMATIC = 0x1,
  CA_LOGO = 0x2,
  CA_CONNECTING = 0x3,
  CA_CHALLENGING = 0x4,
  CA_CONNECTED = 0x5,
  CA_SENDINGSTATS = 0x6,
  CA_LOADING = 0x7,
  CA_PRIMED = 0x8,
  CA_ACTIVE = 0x9,
};

#pragma pack(push, 4)
struct clientUIActive_t
{
  bool active;
  bool isRunning;
  bool cgameInitialized;
  bool cgameInitCalled;
  int keyCatchers;
  bool displayHUDWithKeycatchUI;
  connstate_t connectionState;
  int nextScrollTime;
  bool invited;
  int numVoicePacketsSent;
};
#pragma pack(pop)

typedef enum
{
    DVAR_FLAG_NONE          = 0x0,          //no flags
    DVAR_FLAG_SAVED         = 0x1,          //saves in config_mp.cfg for clients
    DVAR_FLAG_LATCHED       = 0x2,          //no changing apart from initial value (although it might apply on a map reload, I think)
    DVAR_FLAG_CHEAT         = 0x4,          //cheat
    DVAR_FLAG_REPLICATED    = 0x8,          //on change, this is sent to all clients (if you are host)
    DVAR_FLAG_UNKNOWN10     = 0x10,         //unknown
    DVAR_FLAG_UNKNOWN20     = 0x20,         //unknown
    DVAR_FLAG_UNKNOWN40     = 0x40,         //unknown
    DVAR_FLAG_UNKNOWN80     = 0x80,         //unknown
    DVAR_FLAG_USERCREATED   = 0x100,        //a 'set' type command created it
    DVAR_FLAG_USERINFO      = 0x200,        //userinfo?
    DVAR_FLAG_SERVERINFO    = 0x400,        //in the getstatus oob
    DVAR_FLAG_WRITEPROTECTED= 0x800,        //write protected
    DVAR_FLAG_UNKNOWN1000   = 0x1000,       //unknown
    DVAR_FLAG_READONLY      = 0x2000,       //read only (same as 0x800?)
    DVAR_FLAG_UNKNOWN4000   = 0x4000,       //unknown
    DVAR_FLAG_UNKNOWN8000   = 0x8000,       //unknown
    DVAR_FLAG_UNKNOWN10000  = 0x10000,      //unknown
    DVAR_FLAG_DEDISAVED     = 0x1000000,        //unknown
    DVAR_FLAG_NONEXISTENT   = 0xFFFFFFFF    //no such dvar
} dvar_flag;

typedef enum
{
    DVAR_TYPE_BOOL      = 0,
    DVAR_TYPE_FLOAT     = 1,
    DVAR_TYPE_FLOAT_2   = 2,
    DVAR_TYPE_FLOAT_3   = 3,
    DVAR_TYPE_FLOAT_4   = 4,
    DVAR_TYPE_INT       = 5,
    DVAR_TYPE_ENUM      = 6,
    DVAR_TYPE_STRING    = 7,
    DVAR_TYPE_COLOR     = 8,
    //DVAR_TYPE_INT64   = 9 only in Tx
} dvar_type;
// 67/72 bytes figured out
union dvar_value_t {
    char*   string;
    int     integer;
    float   value;
    bool    boolean;
    float   vec2[2];
    float   vec3[3];
    float   vec4[4];
    BYTE    color[4]; //to get float: multiply by 0.003921568859368563 - BaberZz
};
union dvar_maxmin_t {
    int i;
    float f;
};
typedef struct dvar_t
{
    //startbyte:endbyte
    const char*     name; //0:3
    const char*     description; //4:7
    unsigned int    flags; //8:11
    char            type; //12:12
    char            pad2[3]; //13:15
    dvar_value_t    current; //16:31
    dvar_value_t    latched; //32:47
    dvar_value_t    default; //48:64
    dvar_maxmin_t min; //65:67
    dvar_maxmin_t max; //68:72 woooo
} dvar_t;

/* MaterialTextureDef->semantic */
#define TS_2D		0x0
#define TS_FUNCTION	0x1
#define TS_COLOR_MAP	0x2
#define TS_UNUSED_1	0x3
#define TS_UNUSED_2	0x4
#define TS_NORMAL_MAP	0x5
#define TS_UNUSED_3	0x6
#define TS_UNUSED_4	0x7
#define TS_SPECULAR_MAP	0x8
#define TS_UNUSED_5	0x9
#define TS_UNUSED_6	0xA
#define TS_WATER_MAP	0xB

struct __declspec(align(8)) MaterialInfo
{
	const char *name;
	char gameFlags;
	char sortKey;
	char textureAtlasRowCount;
	char textureAtlasColumnCount;
	GfxDrawSurf drawSurf;
	int surfaceTypeBits;
};

struct MaterialStuff
{
	char unk;
	char sortKey;
};

struct Material
{
	const char* name;
	union
	{
		unsigned short flags; // 0x2F00 for instance
		MaterialStuff sort;
	};
	unsigned char animationX; // amount of animation frames in X
	unsigned char animationY; // amount of animation frames in Y
	char unknown1[4]; // 0x00
	unsigned int rendererIndex; // only for 3D models
	char unknown9[4];
	unsigned int surfaceTypeBits;
	unsigned int unknown2; // 0xFFFFFFFF
	unsigned int unknown3; // 0xFFFFFF00
	char unknown4[40]; // 0xFF
	char numMaps; // 0x01, possibly 'map count' (zone code confirms)
	char unknown5; // 0x00
	char unknownCount2; // 0x01, maybe map count actually
	char unknown6; // 0x03
	unsigned int unknown7; // 0x04
	MaterialTechniqueSet* techniqueSet; // '2d' techset; +80
	MaterialTextureDef* maps; // map references
	unsigned int unknown8;
	void* stateMap; // might be NULL, need to test
};

#pragma pack(push, 2)
struct Glyph
{
	unsigned __int16 letter;
	char x0;
	char y0;
	char dx;
	char pixelWidth;
	char pixelHeight;
	float s0;
	float t0;
	float s1;
	float t1;
};
#pragma pack(pop)

struct Font
{
	const char * name;
	int pixelHeight;
	int glyphCount;
	Material* material;
	Material* glowMaterial;
	Glyph * glyphs;
};

// original functions
typedef dvar_t* (__cdecl * Dvar_RegisterBool_t)(const char* name, bool default, int flags, const char* description);
extern Dvar_RegisterBool_t Dvar_RegisterBool;

typedef dvar_t* (__cdecl * Dvar_RegisterInt_t)(const char* name, int default, int min, int max, int flags, const char* description);
extern Dvar_RegisterInt_t Dvar_RegisterInt;


typedef char* (__cdecl* Dvar_InfoString_Big_t)(int typeMask);
extern Dvar_InfoString_Big_t Dvar_InfoString_Big;

typedef dvar_t* (__cdecl * Dvar_FindVar_t)(void);
extern Dvar_FindVar_t _Dvar_FindVar;
dvar_t* Dvar_FindVar(char* name);


typedef int(__cdecl * FS_ReadFile_t)(const char* path, char** buffer);
extern FS_ReadFile_t FS_ReadFile; // fix needed

typedef int (__cdecl * FS_Read_t)(void* buffer, size_t size, int file);
extern FS_Read_t FS_Read;

typedef int (__cdecl * FS_FOpenFileRead_t)(const char* file, int* fh, int uniqueFile);
extern FS_FOpenFileRead_t FS_FOpenFileRead;

typedef int (__cdecl * FS_FCloseFile_t)(int fh);
extern FS_FCloseFile_t FS_FCloseFile;


typedef bool (__cdecl * NET_StringToAdr_t)(netadr_t*);
bool NET_StringToAdr(const char* address, netadr_t* adr);
extern NET_StringToAdr_t NET_StringToAdr_CoD4;

void NET_OutOfBandPrint(int type, netadr_t adr, const char* message, ...);

extern int* svs_numclients;

char* GetStringConvar(char* key);

// inline cmd functions
extern DWORD* cmd_id;
extern DWORD* cmd_argc;
extern DWORD** cmd_argv;

inline int  Cmd_Argc( void )
{
  return cmd_argc[*cmd_id];
}

inline char *Cmd_Argv( int arg )
{
  if ( (unsigned)arg >= cmd_argc[*cmd_id] ) {
    return "";
  }
  return (char*)(cmd_argv[*cmd_id][arg]); 
}

int Cmd_ArgcSV( void );
char *Cmd_ArgvSV( int );