"""specs_s213167.py - batch 213167: multiplayer score board (two team structs on the stack, ordering, winner message, 33 widget strings via the engine formatter), Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def cstr(emu, p, n=80):
    return bytes(emu.rbytes(p, n)).split(b'\0')[0]


def g56e050(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)

    def sp(emu, k):
        fmt = cstr(emu, emu.arg32(1)).replace(b'%i', b'%d')
        s = fmt % emu.arg32(2)
        emu.wbytes(emu.arg32(0), s + b'\0')
        emu.calllog.append(('sprintf', s))
    hook_rec(c, 0x42ac56, 3, pop=0, stackmark=(0,), side=sp, ret=lambda emu, k: 0)
    hook_rec(c, 0x59a5e0, 1, pop=4, this=True)

    flags = [r.choice([0, 1, 1]) for _ in range(4)]
    teams = [r.choice([3, 3, 4, 4, 5, 0]) for _ in range(4)]
    koth = r.choice([0, 1])
    ia, ib = r.sample(range(4), 2)
    flags[ia] = flags[ib] = 1
    teams[ia] = 3
    teams[ib] = r.choice([4, 5, 0])

    def x88(emu, k):
        nm = cstr(emu, emu.arg32(0))
        out = emu.arg32(1)
        emu.calllog.append(('x88', nm))
        if nm.startswith(b'MP_Player') and nm.endswith(b'Team'):
            emu.w32(out, teams[int(nm[9:-4])])
        elif nm == b'MP_KOTHGameType':
            emu.w32(out, koth)
        elif nm == b'MP_NumberOfPlayers':
            emu.w32(out, r.choice([0, 1, 2, 3, 4]))

    def x90(emu, k):
        nm = cstr(emu, emu.arg0 if False else emu.arg32(0))
        emu.calllog.append(('x90', nm))
        emu.wbytes(emu.arg32(1), bytes([flags[int(nm[9:-6])]]))
    X134 = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(0, 1), side=x88),
                         0x90: pystub(c, 2, this=True, stackmark=(0, 1), side=x90)}, nslots=0x60)
    ctrl = rb()

    def x138_88(emu, k):
        emu.calllog.append(('x138', cstr(emu, emu.arg32(0))))
        emu.w32(emu.arg32(1), ctrl)
    X138 = obj(c, 0x20, {0x88: pystub(c, 2, this=True, stackmark=(0, 1), side=x138_88)}, nslots=0x60)

    def n198(emu, k):
        a2 = emu.arg32(2)
        s = b'S%x' % a2
        if a2 == 0x6784f4:
            s += b':%x' % emu.arg32(3)
        emu.wbytes(emu.arg32(1), s + b'\0')
        emu.calllog.append(('n198', s, emu.reg('ecx') == emu.arg32(1)))
    N = obj(c, 0x20, {0x198: pystub(c, 3, pop=0, this=False, stackmark=(1,), side=n198)}, nslots=0x100)
    Z = obj(c, 0x20, {0x0: pystub(c, 2, this=True, ret=lambda emu, k: rb())}, nslots=0x10)
    T = obj(c, 0xb00, {0x134: pystub(c, 0, this=True, ret=X134), 0x138: pystub(c, 0, this=True, ret=X138),
                       0x114: pystub(c, 0, this=True, ret=lambda emu, k: (rb() & ~0xffff) | r.getrandbits(16))}, nslots=0x160)
    w32u(T + 0xae4, Z)
    eng = obj(c, 0x100, {0x190: pystub(c, 0, this=True, ret=N)}, nslots=0x100)
    w32u(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    # route object with the player and team records
    R = rnd(c, 0x200)
    ties = r.choice([0, 1, 2, 3])
    tv = [r.choice([-5, -1, 0, 1, 7, 0x7fffffff, -0x80000000, 3]) for _ in range(6)]
    if ties >= 1:
        tv[3] = tv[0]
    if ties >= 2:
        tv[4] = tv[1]
    if ties >= 3:
        tv[5] = tv[2]
    for j, base in enumerate((0x61, 0x73)):
        e.wbytes(R + base, bytes([r.choice([0, 1, 0x80])]))
        for k in range(3):
            e.wbytes(R + base + 2 + 4 * k, struct.pack('<i', tv[j * 3 + k]))
    Y = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=R)}, nslots=0x100)
    e.w32(0x70038c, Y)

    # logger
    def mlog(emu, k):
        emu.calllog.append(('mlog', cstr(emu, emu.arg32(1))))
    M = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0, this=True, stackmark=(1,), side=mlog)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, Lg)

    # engine global with the 0x2c2d pointer table
    g = rnd(c, 0x2d00)
    w32u(g + 0x2c2d, rb() if r.random() < 0.6 else 0)
    e.w32(0x7003b8, g)

    # this: window message receiver and the 33 widgets
    P44 = obj(c, 0x20, {0x128: pystub(c, 7, pop=0x1c, this=True)}, nslots=0x60)
    O94 = rnd(c, 0x100)
    w32u(O94 + 0x44, P44)
    this = obj(c, 0x240, {}, nslots=0x10)
    w32u(this + 0x94, O94)
    for i in range(33):
        def wlog(emu, k, i=i):
            emu.calllog.append(('w284', i, cstr(emu, emu.arg32(0))))
        wd = obj(c, 0x20, {0x284: pystub(c, 1, this=True, stackmark=(0,), side=wlog)}, nslots=0x300)
        w32u(this + 0x180 + 4 * i, wd)
    import os
    if os.environ.get('DBG'):
        print('M', bytes(e.rbytes(0x20000560, 0x60)).hex())
        print('X134=%x X138=%x N=%x Z=%x Y=%x M=%x Lg=%x' % (X134, X138, N, Z, Y, M, Lg))
        print('R=%x g=%x this=%x O94=%x P44=%x T=%x eng=%x' % (R, g, this, O94, P44, T, eng))
    return [this]


S(0x56e050, 'score_board', 'thiscall', None, ret=None, gen=g56e050)
