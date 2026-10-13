"""specs_s941.py - vehicles batch 941: ZHeli::ClassInit2. Stood in: the base class init (0x5124c0), the root point (0x4db670),
the emitter init and direction (0x516b60, 0x516fd0), the heli's weapon/child slots (0x328, 0x388, 0x38c, 0x8c), the render
manager's 0x50 / 0x58 and the track object (0x25c). The child names are real names from the heli's list."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, cstub


def cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text.encode() + b'\0')
    return a


NAMES = ['Cannon_PosBox_1', 'PilotBox_2', 'WingGun_R_3', 'WingGun_L_4', 'WingRocket_5', 'Misc_6', 'PilotBox_7']


def _cs(em, p):
    out = b''
    while len(out) < 4096:
        b = bytes(em.rbytes(p, 1))
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def g(c):
    def sc(em, r):
        p, ch = em.arg32(0), em.arg32(1) & 0xff
        em.calllog.append(('strchr', 0, 0, (p, ch)))
        s = _cs(em, p)
        k = s.find(bytes([ch])) if ch else len(s)
        em.ret(eax=(p + k) if k >= 0 else 0, argbytes=0)
    c.emu.w32(0x676254, c.emu.stub_fn('strchr', sc))

    def memicmp(em, r):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        res = 0
        for i in range(n):
            x = em.mu.mem_read(a + i, 1)[0]
            y = em.mu.mem_read(b + i, 1)[0]
            x = x + 32 if 65 <= x <= 90 else x
            y = y + 32 if 65 <= y <= 90 else y
            if x != y:
                res = x - y
                break
        em.ret(eax=res & 0xffffffff, argbytes=0)
    c.emu.stub_import('_memicmp', memicmp)

    def stricmp(em, r):
        a, b = _cs(em, em.arg32(0)).lower(), _cs(em, em.arg32(1)).lower()
        res = 0 if a == b else (1 if a > b else -1)
        em.calllog.append(('stricmp', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=res & 0xffffffff, argbytes=0)
    c.emu.stub_import('_stricmp', stricmp)
    ss.patch(c, 0x5124c0, ss.rec(c, 0))
    ss.patch(c, 0x4db670, ss.rec(c, 1))
    ss.patch(c, 0x516b60, ss.rec(c, 3))
    from recruits_util import hook_rec
    hook_rec(c, 0x516fd0, 1, this=True, deref={0: 3})   # its argument is a stack vector: recorded by content
    weapon = obj(c, 0x40)
    heli = obj(c, 0x1000, {0x328: _stub(c, 3, ret=weapon), 0x8c: _stub(c, 1), 0x388: _stub(c, 2), 0x38c: _stub(c, 1, ret=r32(c))})
    head = prev = 0
    for k in range(c.rng.randint(0, 5)):
        ch = _rnd(c, 0x80)
        nameobj = obj(c, 0x20)
        c.emu.w32(nameobj + 4, cstr(c, NAMES[c.rng.randrange(len(NAMES))]))
        c.emu.w32(ch + 0x54, nameobj)
        c.emu.w32(ch + 0x60, 0)
        if prev:
            c.emu.w32(prev + 0x60, ch)
        else:
            head = ch
        prev = ch
    c.emu.w32(heli + 0x50, head)
    for off in (0x44d, 0x451):
        c.emu.w32(heli + off, c.rng.choice([0, 1, 2]))
    c.emu.w32(heli + 0x449, c.rng.choice([0, 1, 2, 3, 4]))
    c.emu.w32(heli + 0x479, 0)
    c.emu.w32(heli + 4, 0 if c.rng.random() < 0.5 else cstr(c, 'Heli1'))
    # render manager: 0x50 gives an id, 0x58 gives an object whose 0xbc takes one arg; the 0x9b object's 0xadc is the
    # track object whose slot 0x25c gives a value
    track = obj(c, 0x40, {0x25c: _stub(c, 2, ret=r32(c))})
    ro = obj(c, 0x1000, {0x50: _stub(c, 1, ret=r32(c)), 0x58: _stub(c, 1, ret=obj(c, 0x40, {0xbc: _stub(c, 1)}))})
    c.emu.w32(ro + 0xadc, track)
    sysm = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(sysm, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(sysm + 0x9b, ro)
    c.emu.w32(0x70039c, sysm)
    dbgo = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgo)})
    c.emu.w32(0x700390, dbg)
    c.emu.w32(0x7003b0, cstub(c, 0))
    c.emu._image_dirty = True
    c.emu.mu.ctl_flush_tb()
    return [heli]


S(0x51be80, "ZHeli::ClassInit2", "thiscall", None, gen=g)
