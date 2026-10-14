"""specs_s34062.py - cascade tier E, batch 34062.
0x601a80 (stdcall): engine table slot 0x58 returns an object (null in a fifth); its +4 name pointer is null or a string among "Ground", "GROUND", "ground", "Gr" and random text; the import _stricmp is a Python stub that
logs both strings and compares case-insensitively; o slot 0x20 returns an object whose +4 is null or a string pointer.
0x620890 (cdecl): [st+0xe0] points at an object whose first dword is a cdecl function stub (four args: the object, edi, esi and a pointer to a stack slot; its side effect changes the slot's value in half the cases and
the stack pointer is not recorded); 0x61dcd0 (seven args) is a recorder; both callees log the busy byte [obj+0x1c] and the four dwords of the guard frame that [st+0x124] points at.
0x6322e0 (cdecl): kind 0, 4, 5, 6 or another value; ctx function pointer at +0x24 is a cdecl recorder; hooked 0x633170 (cdecl, two args); [S+0x38] is null or a stdcall stub (three args, random result); out null in a third."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g601a80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def stricmp(em, res_):
        def rd(p):
            d = b''
            while len(d) < 64:
                b = bytes(em.rbytes(p + len(d), 1))
                if b == b'\0':
                    break
                d += b
            return d
        a, b = rd(em.arg32(0)), rd(em.arg32(1))
        em.calllog.append(('_stricmp', a, b))
        x, y = a.lower(), b.lower()
        em.ret(eax=(0 if x == y else (1 if x > y else 0xffffffff)), argbytes=0)
    e.stub_import('_stricmp', stricmp)

    def sptr():
        if r.random() < 0.3:
            return 0
        s = rnd(c, 0x20)
        e.wbytes(s, r.choice([b'Ground\0', b'GROUND\0', b'ground\0', b'Gr\0', b'Groundx\0', bytes(r.randrange(1, 256) for _ in range(5)) + b'\0']))
        return s
    qq = rnd(c, 0x20)
    e.w32(qq + 4, sptr())
    o = 0 if r.random() < 0.2 else obj(c, 0x20, {0x20: pystub(c, 0, ret=qq, this=True)}, nslots=0x24 // 4)
    if o:
        e.w32(o + 4, sptr())
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True)})
    return [r.getrandbits(32)]


def _g620890(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = rnd(c, 0x140)
    ob = rnd(c, 0x30)

    def probe(em, tag):   # what the guard frame and the busy flag look like while the callee runs
        p = em.r32(st + 0x124)
        em.calllog.append((tag, em.rbytes(ob + 0x1c, 1), tuple(em.r32(p + 4 * i) for i in range(4))))

    def cb(em, k):
        probe(em, 'cb')
        if r.random() < 0.5:
            em.w32(em.arg32(3), r.getrandbits(32))

    def l61(em, k):
        probe(em, '61dcd0')
    fn = pystub(c, 4, ret=lambda em, k: r.getrandbits(32), pop=0, side=cb, stackmark=(3,))
    h = rnd(c, 0x20)
    e.w32(h, fn)
    hook_rec(c, 0x61dcd0, 7, ret=r.getrandbits(32), pop=0, side=l61)
    e.w32(st + 0xe0, h)
    return [st, ob]


def _g6322e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633170, 2, pop=0)
    fn24 = pystub(c, 2, pop=0)
    ctx = rnd(c, 0x40)
    e.w32(ctx + 0x24, fn24)
    S_ = rnd(c, 0x60)
    e.w32(S_, r.choice([0, 4, 5, 6, 4, 5, 6, r.getrandbits(32)]))
    e.w32(S_ + 0x38, 0 if r.random() < 0.4 else pystub(c, 3, ret=lambda em, k: r.getrandbits(32)))
    out = 0 if r.random() < 1 / 3 else rnd(c, 0x10)
    return [S_, ctx, out]


S(0x601a80, 'GUESS name of an object or of its parent when it is the ground', 'stdcall', None, ret='eax', gen=_g601a80, note='batch34062')
S(0x620890, 'GUESS run a loader under a guard frame', 'cdecl', None, ret='eax', gen=_g620890, note='batch34062')
S(0x6322e0, 'GUESS finish a handle: release, reset, rebuild', 'cdecl', None, ret=None, gen=_g6322e0, note='batch34062')
