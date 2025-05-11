#include "cube.h"

extern bool bounce(physent* d, float elasticity, float friction, float gravity);

namespace game
{
    dynent* player1 = new dynent();
    dynent* dummy = new dynent();

    vector<dynent*> dynents;


    dynent* iterdynents(int i)
    {
        if (i == 0) return player1;
        int npcindex = i - 1;
        return npcindex < dynents.length() ? dynents[npcindex] : NULL;
    }


    float abovegameplayhud(int w, int h)
    {
        return 1;
    }

    void adddynlights()
    {
    }

    bool allowedittoggle()
    {
        return execidentbool("allowedittoggle", true);
    }

    bool allowmouselook()
    {
        return true;
    }

    bool allowmove(physent* d)
    {
        return true;
    }

    bool allowthirdperson(bool msg)
    {
        return true;
    }

    const char* autoexec()
    {
        return "autoexec.cfg";
    }

    const char* defaultconfig()
    {
        return "data/defaults.cfg";
    }

    const char* defaultcrosshair(int index)
    {
        return "data/crosshair.png";
    }

    const char* restoreconfig()
    {
        return "restore.cfg";
    }

    const char* savedconfig()
    {
        return "config.cfg";
    }

    const char* savedservers()
    {
        return NULL;
    }

    void bounced(physent* d, const vec& surface)
    {
    }

    bool canjump() {
        return true;
    }

    void changemap(const char* name)
    {
        changemap(name);
    }

    int clipconsole(int w, int h)
    {
        return 0;
    }

    bool collidecamera()
    {
        return true;
    }

    void connectattempt(const char* name, const char* password, const ENetAddress& address)
    {
    }

    void connectfail()
    {
    }

    bool detachcamera()
    {
        return false;
    }

    void doattack(bool on)
    {
    }

    void dynentcollide(physent* d, physent* o, const vec& dir)
    {
    }

    void dynlighttrack(physent* owner, vec& o, vec& hud)
    {
    }

    void edittoggled(bool on)
    {
    }

    void edittrigger(const selinfo& sel, int op, int arg1, int arg2, int arg3, const VSlot* vs)
    {
    }

    void forceedit(const char* name)
    {
        changemap(name);
    }

    void g3d_gamemenus()
    {
    }

    void gameconnect(bool _remote)
    {
        if (editmode) toggleedit();
    }

    void gamedisconnect(bool cleanup)
    {
    }

    const char* gameident()
    {
        return "fps";
    }

    void gameplayhud(int w, int h)
    {
    }

    const char* getclientmap()
    {
        return "";
    }

    const char* getmapinfo()
    {
        return NULL;
    }

    const char* getscreenshotinfo()
    {
        return NULL;
    }

    void initclient()
    {
    }

    bool ispaused()
    {
        return false;
    }

    void lighteffects(dynent* e, vec& color, vec& dir)
    {
    }

    void loadconfigs()
    {
    }

    void loadingmap(const char* name)
    {
    }

    int maxsoundradius(int n)
    {
        return 500;
    }

    bool needminimap()
    {
        return false;
    }

    void newmap(int size)
    {
    }

    int numdynents()
    {
        return 0;
    }

    void parseoptions(vector<const char*>& args)
    {
    }

    void parsepacketclient(int chan, packetbuf& p)
    {
    }

    void particletrack(physent* owner, vec& o, vec& d)
    {
    }

    void physicstrigger(physent* d, bool local, int floorlevel, int waterlevel, int material)
    {
    }

    void preload()
    {
    }

    float ratespawn(dynent* d, const extentity& e)
    {
        return 1.0f;
    }

    void readgamedata(vector<char>& extras)
    {
    }

    void renderavatar()
    {
    }
    
    void rendergame(bool mainpass)
    {
        setbbfrommodel(dummy, "mrfixit");
        rendermodel(NULL, "mrfixit", ANIM_IDLE | ANIM_LOOP, vec(dummy->o).sub(vec(0, 0, dummy->eyeheight)), dummy->yaw + 90, dummy->pitch, MDL_CULL_VFC | MDL_CULL_DIST | MDL_CULL_OCCLUDED | MDL_LIGHT, dummy);

        //renderclient(dummy, "mrfixit", NULL, 0, ANIM_ATTACK1, 300, 0.0, 0, 0, false);
    }

    void renderplayerpreview(int model, int team, int weap)
    {
    }

    void resetgamestate()
    {
    }

    int scaletime(int t)
    {
        return t * 100;
    }

    int selectcrosshair(vec& color)
    {
        return 0;
    }

    bool serverinfostartcolumn(g3d_gui* g, int i)
    {
        return false;
    }
    void serverinfoendcolumn(g3d_gui* g, int i)
    {
    }
    bool serverinfoentry(g3d_gui* g, int i, const char* name, int port, const char* sdesc, const char* map, int ping, const vector<int>& attr, int np)
    {
        return false;
    }

    void setupcamera()
    {
        //camera1 = player1;
    }

    void startmap(const char* name)
    {
        // player position
        player1->o = vec(512.0f, 512.0f, 530.0f);  // Example coordinates

        // player state
        player1->state = CS_ALIVE;
        player1->type = ENT_PLAYER;

        // physics properties if needed
        player1->vel = vec(0, 0, 0);
        player1->yaw = 269.636f;
        player1->pitch -30.90f;
        player1->roll = 0.0f;

        player1->radius = 4.1f;
        player1->eyeheight = 14.0f;
        player1->aboveeye = 1.0f;

        player1->collidetype = COLLIDE_ELLIPSE;
        player1->physstate = PHYS_FALL;

        player1->reset();

        //setbbfrommodel(player1, "mrfixit");
        entinmap(player1);
        //renderclient(player1, "mrfixit", NULL, 0, ANIM_ATTACK1, 300, 0.0, 0);
        
        dummy->o = vec(550.0f, 512.0f, 550.0f);
        dummy->state = CS_ALIVE;
        dummy->type = ENT_AI;
        dummy->physstate = PHYS_FALL;
        dummy->collidetype = COLLIDE_ELLIPSE_PRECISE;
        dummy->eyeheight = 14.0f;
         
        dummy->reset();
        entinmap(dummy);
        dynents.add(dummy);
    }

    vec cross(const vec& a, const vec& b)
    {
        return vec(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    void updateworld()
    {
        if (dummy)
        {
            static float t = 0;
            t += 0.1f;

            vec velocity = dummy->vel;
            velocity.z = 0;
            float speed = velocity.magnitude();

            if (speed > 1e-3f)
            {
                vec rollAxis = cross(vec(0, 0, 1), velocity).normalize();
                float angularSpeed = speed / dummy->radius;

                dummy->pitch = -rollAxis.x * angularSpeed;
                dummy->yaw += rollAxis.y * angularSpeed / 3;
                //dummy->roll = rollAxis.y * angularSpeed;
                moveragdoll(dummy);
            }

            float dist = dummy->o.dist(player1->o);
            if (dist < 10.0f)
            {
                vec push = vec(dummy->o).sub(player1->o).normalize();
                push.mul(30.0f);
                dummy->vel.add(push);
            }

            bounce(dummy, 0.5f, 0.0f, 1.8f);
        }

        moveplayer(player1, 10, true);
        physicsframe();
    }

    void suicide(physent* d)
    {
    }

    void toserver(char* text)
    {
    }

    void vartrigger(ident* id)
    {
    }

    void writeclientinfo(stream* f)
    {
    }

    void writegamedata(vector<char>& extras)
    {
    }
}

namespace entities
{
    using namespace game;

    // Storage

    vector<extentity*> ents;

    vector<extentity*>& getents()
    {
        return ents;
    }

    // Entity creation / deletion

    extentity* newentity()
    {
        return NULL;
    }

    void deleteentity(extentity* e)
    {
    }

    void clearents()
    {
    }

    // Attachment and relationships

    bool mayattach(extentity& e)
    {
        return false;
    }

    bool attachent(extentity& e, extentity& a)
    {
        return false;
    }

    // Model and animation

    void animatemapmodel(const extentity& e, int& anim, int& basetime)
    {
    }

    const char* entmodel(const entity& e)
    {
        return NULL;
    }

    // Editing

    void editent(int i, bool local)
    {
    }

    void fixentity(extentity& e)
    {
    }

    void entradius(extentity& e, bool color)
    {
    }

    bool printent(extentity& e, char* buf, int len)
    {
        return false;
    }

    void readent(entity& e, char* buf, int ver)
    {
    }

    void writeent(entity& e, char* buf)
    {
    }

    // Extra entity info

    int extraentinfosize()
    {
        return NULL;
    }

    // Identification

    const char* entnameinfo(entity& e)
    {
        return "";
    }

    const char* entname(int i)
    {
        static const char* entnames[] =
        {
            "none?"
        };
        return i >= 0 && size_t(i) < sizeof(entnames) / sizeof(entnames[0]) ? entnames[i] : "";
    }

    // Physics

    float dropheight(entity& e)
    {
        return 1.0;
    }
}

namespace server
{
    void* newclientinfo() { return NULL; }
    void deleteclientinfo(void* ci) {}
    void serverinit() {}
    int reserveclients() { return 0; }
    int numchannels() { return 0; }
    void clientdisconnect(int n) {}
    int clientconnect(int n, uint ip) { return DISC_NONE; }
    void localdisconnect(int n) {}
    void localconnect(int n) {}
    bool allowbroadcast(int n) { return true; }
    void recordpacket(int chan, void* data, int len) {}
    void parsepacket(int sender, int chan, packetbuf& p) {}
    void sendservmsg(const char* s) {}
    bool sendpackets(bool force) { return false; }
    void serverinforeply(ucharbuf& req, ucharbuf& p) {}
    void serverupdate() {}
    bool servercompatible(char* name, char* sdec, char* map, int ping, const vector<int>& attr, int np) { return true; }

    int serverinfoport(int servport) { return 0; }
    int serverport(int infoport) { return 0; }
    const char* defaultmaster() { return ""; }
    int masterport() { return 0; }
    int laninfoport() { return 0; }
    void processmasterinput(const char* cmd, int cmdlen, const char* args) {}
    void masterconnected() {}
    void masterdisconnected() {}
    bool ispaused() { return false; }
    int scaletime(int t) { return t * 100; }
}


void changemap(const char* name, int mode) // request map change, server may ignore
{
    //server::forcemap(name, mode);
    if (!isconnected()) localconnect();
    if (!load_world(name)) emptymap(0, true, name);
}

ICOMMAND(map, "si", (char* name, int mode), changemap(name, mode));