"""specs_s313.py - own slice (residue 15), batch 313: 0x5c53f0 CTargetObtained::Command(unsigned short, void*) (thiscall, ret 8).
The engine global 0x70039c points to a fake engine whose +0x9b is a fake 'dat' object (slots 0x58, 0x114, 0x138); its +0xae4 is a
string object (slot 0). Out-pointer arguments (0x88 arg 1, 0x114 arg 4, 0x4c arg 0) are logged as ('w', value) instead of the stack
address, because the stack slot is reused by later exe code and its end-of-run bytes differ between the two frames.
Helpers 0x5c5620, 0x5c5810, 0x589c20, 0x59a580, 0x596940 run as exe code. All random values are drawn in gen."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _h(name, off, nargs, ret, ptr=None, wv=0, mask=None):
    # mask: a stack argument the caller never initializes (its value depends on frame layout); logged as 0 on both sides
    def h(em, r):
        a = [em.arg32(k) for k in range(nargs)]
        logged = list(a)
        if mask is not None:
            logged[mask] = 0
        if ptr is not None and a[ptr]:
            em.w32(a[ptr], wv)
            logged[ptr] = ('w', wv)
        em.calllog.append((name, off, em.reg('ecx'), tuple(logged)))
        em.ret(eax=ret, argbytes=4 * nargs)
    return h


def _stricmp(em, r):
    # cdecl import: _stricmp(a, b), case-insensitive; the port only tests the result against zero
    a, b = em.arg32(0), em.arg32(1)
    i = 0
    while True:
        x = em.mu.mem_read(a + i, 1)[0]
        y = em.mu.mem_read(b + i, 1)[0]
        lx = x + 32 if 65 <= x <= 90 else x
        ly = y + 32 if 65 <= y <= 90 else y
        if lx != ly or x == 0:
            em.ret(eax=(lx - ly) & 0xffffffff, argbytes=0)
            return
        i += 1


def _h59a580(em, r):
    # 0x59a580(x, s, -1, 0), thiscall, ret 0xc: recorded (ECX and the three arguments), returns nothing
    em.calllog.append(('h59a580', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
    em.ret(eax=0, argbytes=12)


def _h589c20(em, r):
    # 0x589c20(a), stdcall ret 4, reads [ECX + a*4 + 0x2c2d]: recorded, returns that dword
    ecx, a = em.reg('ecx'), em.arg32(0)
    em.calllog.append(('h589c20', 0, ecx, (a,)))
    v = struct.unpack('<I', bytes(em.mu.mem_read(ecx + a * 4 + 0x2c2d, 4)))[0]
    em.ret(eax=v, argbytes=4)


def _h596940(em, r):
    # 0x596940(a, p, b, c), thiscall-style with ECX = e.[0x852], ret 0x10: recorded; p is an out pointer the stub does not write
    em.calllog.append(('h596940', 0, em.reg('ecx'), (em.arg32(0), 'p', em.arg32(2), em.arg32(3))))
    em.ret(eax=0, argbytes=16)


def _gen(c):
    e = c.emu
    rng = c.rng
    e.stub_import('_stricmp', _stricmp)
    e.hook(0x59a580, _h59a580)
    e.hook(0x589c20, _h589c20)
    e.hook(0x596940, _h596940)
    self_ = _rnd(c, 0x200)  # the CTargetObtained block: random, fields below set explicitly
    word = rng.getrandbits(16)
    e.wbytes(self_ + 0x148, word.to_bytes(2, 'little'))
    e.wbytes(self_ + 0x152, bytes([rng.choice([0, 0, 1])]))
    cmd = word if rng.random() < 0.6 else rng.getrandbits(16)
    data = rng.getrandbits(32)

    strp = 0x677b5a if rng.random() < 0.5 else e.cstr(rng.choice(['abc', '0x1', 'zz', '']))
    strobj = c.emu.alloc(0x20, 4)
    e.w32(strobj, e.fake_vtable('cmd_str', 4, {0: _h('cmd_str', 0, 2, strp)}))

    tval = rng.getrandbits(32)
    o = c.emu.alloc(0x40, 4)
    e.w32(o, e.fake_vtable('cmd_o', 0x30, {0x88: _h('cmd_o', 0x88, 2, o, ptr=1, wv=tval)}))

    wsub = rng.getrandbits(32)
    rsub = rng.getrandbits(32)
    # Two objects: object A (key t, the 0x88 out value) has a one-argument slot 0x128 (block A and 0x5c5620 push one word);
    # object B (any other key, the self+0x14e dword of 0x5c5810) has a three-argument slot 0x128 (0x5c5810 pushes three words).
    al_a = rng.choice([0, 1])
    al_b = rng.choice([0, 1])
    sub = c.emu.alloc(0x40, 4)
    e.w32(sub, e.fake_vtable('cmd_sub', 0x30, {0x4c: _h('cmd_sub', 0x4c, 1, 0, ptr=0, wv=wsub),
                                              0x5c: _h('cmd_sub', 0x5c, 1, rsub, ptr=0, wv=0)}))
    eoA = c.emu.alloc(0x1000, 4)
    e.w32(eoA, e.fake_vtable('cmd_eA', 0x80, {0x128: _h('cmd_e', 0x128, 1, 0),
                                             0x1e0: _h('cmd_e', 0x1e0, 1, al_a)}))
    eoB = c.emu.alloc(0x1000, 4)
    e.w32(eoB, e.fake_vtable('cmd_eB', 0x80, {0x128: _h('cmd_e', 0x128, 3, 0),
                                             0x1e0: _h('cmd_e', 0x1e0, 1, al_b)}))
    for x in (eoA, eoB):
        e.w32(x + 0x852, rng.choice([0, 0, 1, 0x1234]))   # a value only: the hook never dereferences it
        e.w32(x + 0x18, sub if rng.random() < 0.6 else 0)

    zero58 = rng.random() < 0.1
    w_ret = rng.getrandbits(16)
    # 0x5c5620 returns the dword this stub writes: zero lets the port go on past the check (60% of cases)
    kval = 0 if rng.random() < 0.6 else rng.getrandbits(32)

    def h58(em, r):
        a0 = em.arg32(0)
        em.calllog.append(('cmd_dat', 0x58, em.reg('ecx'), (a0,)))
        em.ret(eax=0 if zero58 else (eoA if a0 == tval else eoB), argbytes=4)

    ob = c.emu.alloc(0x100, 4) if rng.random() < 0.7 else 0
    dat = c.emu.alloc(0xb00, 4)
    e.w32(dat, e.fake_vtable('cmd_dat', 0x80, {
        0x58: h58,
        0x114: _h('cmd_dat', 0x114, 6, w_ret, ptr=4, wv=kval, mask=5),
        0x138: _h('cmd_dat', 0x138, 0, o),
        0x60: _h('cmd_dat', 0x60, 1, ob)}))
    e.w32(dat + 0xae4, strobj)

    # 0x589c20 reads [ECX + 4a + 0x2c2d] with ECX = [0x7003b8] (a = 0 in this batch); 0x59a580 uses the dword as its object
    gb = c.emu.alloc(0x3000, 4)
    xo = c.emu.alloc(0x2000, 4)
    e.w32(xo + 0x1d0f, 0)
    e.w32(gb + 0x2c2d, xo)
    e.w32(0x7003b8, gb)

    eng = c.emu.alloc(0x200, 4)
    e.w32(eng + 0x9b, dat)
    e.w32(0x70039c, eng)
    return [self_, cmd, data]


S(0x5c53f0, 'CTargetObtained::Command (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='batch313; ret 8; helpers 0x5c5620/0x5c5810/0x589c20/0x59a580/0x596940 run as exe code')
