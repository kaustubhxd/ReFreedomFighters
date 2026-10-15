"""specs_s1602.py - soundtimers batch 1602: ZFFActor shouts (PlaySound_Enum, _Command, _Keep, ExpandSoundset) and
ZFFGameData::GetGameOSD.

The actor is a ZIKLNKOBJ world (sthelp.world) plus the ZFFActor fields; CanIPlay runs (exe code in the original run,
the port in the port run) on a timer table built around the current tick count. CRT new/delete/memset/sprintf and
ZGameOSD::AddActorActionMarker are hooked; FindInSoundSet is a Python stub that logs the pattern string it gets
(the buffer is on the stack, so its address differs between the two runs) and answers with a hash of it."""
import struct
import zlib
from pilot import S
from sthelp import rnd, obj, stub, Seq, world, hook, _cc, _timers


def _osd(c):
    return [rnd(c, 0x3000), c.rng.choice([0, 1, 2, 3, 0x7f, 0x80, 0xff, c.rng.getrandbits(32)])]


S(0x589c20, 'ZFFGameData::GetGameOSD', 'thiscall', None, ret='eax', gen=_osd, note='batch1602; signed byte index')


def _crt(c, seq):
    """Hooks for new / delete / memset / sprintf (cdecl, caller pops)."""
    def new(e):
        n = e.r32(e.reg('esp') + 4)
        return e.alloc(n, 16)
    hook(c, seq, 0x41e290, 1, ret=new, this=False, pop=False)
    hook(c, seq, 0x634273, 2, this=False, pop=False)

    def memset(e, r):
        sp = e.reg('esp')
        d, v, n = e.r32(sp + 4), e.r32(sp + 8), e.r32(sp + 12)
        e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d)
    c.emu.hook(0x634d10, memset)
    from sthelp import HOOKED
    HOOKED.add(0x634d10)

    def sprintf(e, r):
        sp = e.reg('esp')
        buf, fmt, v = e.r32(sp + 4), e.r32(sp + 8), e.r32(sp + 12)
        f = bytes(e.rbytes(fmt, 16)).split(b'\0')[0].decode()
        s = f.replace('%i', str(struct.unpack('<i', struct.pack('<I', v))[0])).encode() + b'\0'
        e.wbytes(buf, s)
        e.ret(eax=len(s) - 1)
    c.emu.hook(0x42ac56, sprintf)
    HOOKED.add(0x42ac56)


def _findset(c, seq):
    """Python stub for ZDllSound::FindInSoundSet(set, pattern): logs (set, pattern) on the heap, returns crc32."""
    log = c.emu.alloc(4 + 60 * 24, 4)

    def h(e, r):
        sp = e.reg('esp')
        st, pat = e.r32(sp + 4), e.r32(sp + 8)
        s = bytes(e.rbytes(pat, 16)).split(b'\0')[0]
        n = e.r32(log)
        if n < 60:
            e.w32(log + 4 + 24 * n, st)
            e.wbytes(log + 8 + 24 * n, s[:16])
        e.w32(log, n + 1)
        k = e.r32(seq.addr) + 1
        e.w32(seq.addr, k)
        e.ret(eax=zlib.crc32(s) ^ st, argbytes=8)
    return c.emu.stub_fn('FindInSoundSet', h)


def actor(c, seq):
    r = c.rng
    pitch = r.choice([0, 50, -25, 25, r.getrandbits(32)])
    soundset = r.getrandbits(32) if r.random() < 0.85 else 0
    slots = {0x680: stub(c, seq, 0, ret=soundset), 0x684: stub(c, seq, 0, ret=pitch), 0x6ec: stub(c, seq, 3)}
    me, hc, hn = world(c, seq, size=0xa00, slots=slots, dll_slots={0x60: _findset(c, seq)})
    _crt(c, seq)
    s = c.emu.r32(0x70039c)
    now = c.emu.r32(s + 0x40)
    cc = _cc(c, seq) if r.random() < 0.9 else 0
    if cc:
        _timers(c, cc, now)
    c.emu.w32(me + 0x93a, cc)
    tm = rnd(c, 0x10)
    c.emu.w32(tm + 4, r.choice([0, 1, 2, 3, 5, r.getrandbits(32)]))
    c.emu.w32(me + 0x54, tm)
    expanded = r.random() < 0.3
    n = 98 if expanded else 38
    tab = c.emu.alloc(4 * 98 + 8, 4)    # 98 slots either way, so enums 38..97 read defined memory
    for i in range(98):
        c.emu.w32(tab + 4 * i, r.getrandbits(32))
    c.emu.w32(me + 0x936, tab)
    c.emu.w8(me + 0x93e, 1 if expanded else r.choice([0, 0, 0, 2]) * (0 if r.random() < 0.8 else 1))
    hero = rnd(c, 0x700)
    c.emu.w32(hero + 0x684, r.choice([1, 2, 0, 0x101, r.getrandbits(32)]))
    c.emu.w32(me + 0x92e, hero if r.random() < 0.5 else 0)
    gd = rnd(c, 0x2c2d + 0x400 + 0x10)
    c.emu.w32(0x7003b8, gd)
    hook(c, seq, 0x598e10, 3, ret=r.getrandbits(32))
    return me


def _enum_arg(c):
    r = c.rng
    k = r.random()
    e = r.randint(0, 38) if k < 0.6 else (r.randint(39, 97) if k < 0.85 else r.choice([0x23, 0x22, 4, 5, 38]))
    return e | (r.getrandbits(24) << 8 if r.random() < 0.3 else 0)


def _expand(c):
    seq = Seq(c)
    return [actor(c, seq)]


S(0x59fb50, 'ZFFActor::ExpandSoundset', 'thiscall', None, ret=None, gen=_expand,
  note='batch1602; 38 -> 98 entries, "*_0%i*" / "*_%i*" lines from the actor sound set')


def _enum(c):
    seq = Seq(c)
    me = actor(c, seq)
    r = c.rng
    hero2 = rnd(c, 0x700) if r.random() < 0.7 else 0
    if hero2:
        c.emu.w32(hero2 + 0x684, r.choice([1, 2, 0, r.getrandbits(32)]))
    return [me, _enum_arg(c), r.choice([0, 1, 0x100, r.getrandbits(32)]), hero2]


S(0x5a1b50, 'ZFFActor::PlaySound_Enum', 'thiscall', None, ret='eax', gen=_enum,
  note='batch1602; CanIPlay, expansion above 38, speech, optional OSD action marker')


def _keep(c):
    seq = Seq(c)
    me = actor(c, seq)
    e = c.rng.randint(0, 37) | (c.rng.getrandbits(24) << 8 if c.rng.random() < 0.3 else 0)
    return [me, e]


S(0x5a1c20, 'ZFFActor::PlaySound_Enum_Keep', 'thiscall', None, ret='eax', gen=_keep, note='batch1602')


def _command(c):
    seq = Seq(c)
    me = actor(c, seq)
    r = c.rng
    e = r.choice([0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x1b]) if r.random() < 0.7 else _enum_arg(c)
    if r.random() < 0.3:
        e |= r.getrandbits(24) << 8
    d = r.choice([0, 0, 500, 1000, r.randint(1, 3000), r.getrandbits(32)])
    return [me, e, d, r.choice([0, 1, 0x100, r.getrandbits(32)])]


S(0x5a1ac0, 'ZFFActor::PlaySound_Command', 'thiscall', None, ret=None, gen=_command,
  note='batch1602; recruit reply: delayed on-screen, immediate on-screen, or speech with a start delay')
