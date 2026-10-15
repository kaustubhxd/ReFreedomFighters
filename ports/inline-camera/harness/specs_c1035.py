"""specs_c1035.py - camera batch 1035: ZCamHelper::InitRecruitWayPoints. A chain of geometry objects with random
names (waypoint spellings, NONAME, empty, other) and random positions; the world iterator (slot 0x50) walks the chain;
the debug draw (slot 0x238) logs its inputs (not the stack addresses)."""
import struct
from pilot import S
from camgen import rnd, fbits, Log, handler, sys_with_mgr


def _cstr(c, text):
    p = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(p, text.encode('latin-1') + b'\0')
    return p


def _wp(c):
    r = c.rng
    log = Log(c, 1024)

    def mreset(e, res):  # mreset gets a stack matrix in ECX: log the tag only
        log.put(0x4de7a0)
        e.ret(argbytes=0)
    c.emu.hook(0x4de7a0, mreset)

    def strchr(e, res):  # cdecl strchr(s, c): the caller pops; returns a pointer to the first c or 0
        base, want = e.arg32(0), e.arg32(1) & 0xff
        p = 0
        for i in range(256):
            ch = e.r8(base + i)
            if ch == want:
                p = base + i
                break
            if ch == 0:
                break
        e.ret(eax=p, argbytes=0)
    c.emu.stub_import('strchr', strchr)

    def memicmp(e, res):  # cdecl _memicmp(a, b, n): the caller pops; 0 when equal ignoring case
        a, b, n = e.arg32(0), e.arg32(1), e.arg32(2)
        va = bytes(e.r8(a + i) for i in range(n)).lower()
        vb = bytes(e.r8(b + i) for i in range(n)).lower()
        v = (va > vb) - (va < vb)
        e.ret(eax=v & 0xffffffff, argbytes=0)
    c.emu.stub_import('_memicmp', memicmp)

    def stricmp(e, res):  # cdecl _stricmp(a, b): the caller pops; case-insensitive C-string compare
        def cs(addr):
            out = b''
            for i in range(256):
                ch = e.r8(addr + i)
                if ch == 0:
                    break
                out += bytes([ch])
            return out.lower()
        a, b = cs(e.arg32(0)), cs(e.arg32(1))
        e.ret(eax=((a > b) - (a < b)) & 0xffffffff, argbytes=0)
    c.emu.stub_import('_stricmp', stricmp)
    s = sys_with_mgr(c, 0x100)

    def show(e, res):
        log.put(0x5c)
        e.ret(eax=r.choice([0, 1]), argbytes=8)

    def rnd_(e, res):
        log.put(0x1c0, e.arg32(1))
        e.ret(st0=r.uniform(0.0, 1.0), argbytes=8)
    vt = c.emu.fake_vtable('sys', 0x1c4 // 4, {0x5c: show, 0x1c0: rnd_})
    c.emu.w32(s, vt)

    names = ['*waypoint*', '*WAYPOINT*', '<NONAME>', 'Door', 'waypoint2', None]
    geoms = []
    for i in range(r.randint(0, 6)):
        def pos(e, res):  # object getter (vslot 0x84): writes a random position
            out = e.arg32(0)
            for k in range(3):
                e.w32(out + 4 * k, fbits(c))
            e.ret(argbytes=4)
        obj = c.emu.fake_object('obj', 0x60, slots={0x84: pos})
        nm = r.choice(names)
        c.emu.w32(obj + 4, _cstr(c, nm) if nm else 0)
        g = c.emu.fake_object('geom', 0x60)
        c.emu.w32(g + 0x54, obj)
        geoms.append(g)

    def nxt(e, res):  # world iterator (vslot 0x50(out*)): out = the geometry after *out, or 0
        out = e.arg32(0)
        cur = e.r32(out)
        idx = geoms.index(cur) if cur in geoms else -1
        nx = geoms[idx + 1] if 0 <= idx + 1 < len(geoms) else 0
        e.w32(out, nx)
        e.ret(argbytes=4)

    def draw(e, res):  # debug draw (mat, pos*, size*, colour, flag): log values only
        pos, size = e.arg32(1), e.arg32(2)
        log.put(0x238, e.arg32(3), e.arg32(4), *[e.r32(pos + 4 * k) for k in range(3)],
                *[e.r32(size + 4 * k) for k in range(3)])
        e.ret(argbytes=20)
    world = c.emu.fake_object('world', 0x20, slots={0x50: nxt, 0x238: draw})
    c.emu.w32(world + 8, geoms[0] if geoms else 0)
    m = c.emu.fake_object('mgr', 0x1000, slots={})
    c.emu.w32(m + 0xadc, world)
    c.emu.w32(s + 0x9b, m)
    self_ = rnd(c, 0xf00)
    return [self_]


S(0x5d0310, 'ZCamHelper::InitRecruitWayPoints', 'thiscall', gen=_wp)
