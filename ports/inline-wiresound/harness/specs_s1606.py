"""specs_s1606.py - soundtimers batch 1606: ZFFActor::PlaySound_Enum_On_Screen.
Built on the batch 1602 actor. Extra: positions (Python stubs filling the caller's vector), the wave-path chain on the
sound DLL, the ResourceCollection lookup (hooked: logs the key string, answers a resource or 0), MessageDialog and
AddActorActionMarker (hooked recorders), and the /GS range-check failure (hooked: stops the run)."""
import struct
import zlib
from pilot import S
from sthelp import rnd, obj, stub, Seq, hook, HOOKED
from specs_s1602 import actor, _enum_arg


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 8, 4)
    c.emu.wbytes(a, s.encode() + b'\0')
    return a


def _vecstub(c, seq, v):
    def h(e, r):
        out = e.r32(e.reg('esp') + 4)
        for i in range(3):
            e.mu.mem_write(out + 4 * i, struct.pack('<f', v[i]))
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        e.ret(argbytes=4)
    return c.emu.stub_fn('GetPosition', h)


def _osscreen(c):
    seq = Seq(c)
    r = c.rng
    me = actor(c, seq)
    s = c.emu.r32(0x70039c)
    if r.random() < 0.1:
        c.emu.w32(s + 0x1b5d, 1)
    # positions: mostly in range
    hp = [r.uniform(-1e4, 1e4), r.uniform(-500, 500), r.uniform(-1e4, 1e4)]
    k = r.random()
    if k < 0.75:
        mp = [hp[0] + r.uniform(-1100, 1100), hp[1] + r.uniform(-300, 300), hp[2] + r.uniform(-1100, 1100)]
    elif k < 0.9:   # horizontally close, vertically around the 350 edge
        mp = [hp[0] + r.uniform(-500, 500), hp[1] + r.choice([-1, 1]) * r.uniform(250, 450), hp[2] + r.uniform(-500, 500)]
    else:
        mp = [hp[0] + r.uniform(-3000, 3000), hp[1] + r.uniform(-600, 600), hp[2] + r.uniform(-3000, 3000)]
    hero = obj(c, 0x900, {0x84: _vecstub(c, seq, hp)})
    osd = rnd(c, 0x20)
    c.emu.w32(hero + 0x852, osd)
    c.emu.w32(me + 0x92e, hero)
    vt = c.emu.r32(me)
    c.emu.w32(vt + 0x84, _vecstub(c, seq, mp))
    # wave path chain on the DLL (the DLL vtable has room: obj size 0x40 vtable sized by max slot; rebuild it)
    dll = c.emu.r32(s + 0x1a9f)
    if not dll:   # the on-screen path always has a sound DLL (the original dereferences it unchecked)
        dll = obj(c, 0x200, {})
        c.emu.w32(s + 0x1a9f, dll)
    if dll:
        old = c.emu.r32(dll)
        nvt = c.emu.alloc(0x200, 4)
        for off in (0x60, 0xf0):
            c.emu.w32(nvt + off, c.emu.r32(old + off))
        name = r.choice(['C01A_44_Jones', 'Soldier_Panic_03', 'Civ_M1_Pain'])
        path = r.choice(['Voices/%s/%s.wav', 'a/b/c/%s%s.wav']) % ('C01A', name)   # two slashes: the key has a second '/'
        p3 = _cstr(c, path)
        p2 = rnd(c, 8) if r.random() < 0.95 else 0
        p1 = rnd(c, 8) if r.random() < 0.95 else 0
        c.emu.w32(nvt + 0x40, stub(c, seq, 1, ret=p1))
        c.emu.w32(nvt + 0x1dc, stub(c, seq, 1, ret=p2))
        c.emu.w32(nvt + 0x1e8, stub(c, seq, 1, ret=p3))
        c.emu.w32(dll, nvt)
    # database with a ResourceCollection at +0xae4
    db = c.emu.r32(s + 0x9b)
    ndb = rnd(c, 0xb00)
    c.emu.w32(ndb, c.emu.r32(db))
    c.emu.w32(ndb + 0xae4, rnd(c, 0x10) if r.random() < 0.9 else 0)
    c.emu.w32(s + 0x9b, ndb)
    missing = set(x for x in ('key', 'name') if r.random() < 0.2)
    log = c.emu.alloc(4 + 2 * 40, 4)

    def getres(e, rr):
        sp = e.reg('esp')
        key = bytes(e.rbytes(e.r32(sp + 4), 40)).split(b'\0')[0]
        n = e.r32(log)
        if n < 2:
            e.wbytes(log + 4 + 40 * n, key[:39])
        e.w32(log, n + 1)
        e.w32(seq.addr, e.r32(seq.addr) + 1)
        kind = 'name' if key.startswith(b'/Names/') else 'key'
        if kind in missing:
            e.ret(eax=0, argbytes=8)
            return
        ent = e.alloc(48, 4)
        e.wbytes(ent, bytes([1 if zlib.crc32(key) & 3 else 0]) + key[:40] + b'\0')
        res = e.alloc(8, 4)
        e.w32(res, ent)
        e.ret(eax=res, argbytes=8)
    c.emu.hook(0x49df60, getres)
    HOOKED.add(0x49df60)
    hook(c, seq, 0x59a5b0, 3)
    ch = obj(c, 0x40, {0x2c: stub(c, seq, 3, pop=False, skip=(2,))})   # arg 2 is the key buffer on the stack
    lg = obj(c, 0x40, {0x20: stub(c, seq, 2, ret=ch)})
    c.emu.w32(0x700390, lg)

    def rangefail(e, rr):
        e.stop('rangecheck failure (noreturn)', ok=False)
    c.emu.hook(0x634047, rangefail)
    HOOKED.add(0x634047)
    spk = r.choice([0, _cstr(c, 'Jones'), _cstr(c, 'Troy'), _cstr(c, '')])
    return [me, _enum_arg(c), spk, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x5a1c50, 'ZFFActor::PlaySound_Enum_On_Screen', 'thiscall', None, ret='eax', gen=_osscreen,
  note='batch1606; range check, speech, subtitle key from the wave path, /Names/ speaker, MessageDialog')
