"""specs_s34056.py - cascade tier E, batch 34056.
0x462040: the real 0x610100 stub runs; hooked 0x4e1070 (thiscall, writes a random NUL-terminated string of 0..60 bytes into its stack buffer and records only the stream) and 0x4e1b30 (returns a random value); this
slot 0x2f4 logs the string it receives (stack pointer) plus its second argument and returns a random value; the /GS check keeps EAX; the return value (EAX) is compared.
0x464460: f is zero in half the cases; engine table slots 0x114 (four stack args, returns a 32-bit value whose low word is used), 0x138 (returns an object whose slot 0x88 writes a random tmp through its stack pointer
argument) and 0x4c are recorders; this slot 0x12c (three args) records.
0x476b50: counter [this+0x60] in 1..4 (1 triggers the reload from [this+0x5c]); array at [this+0x68] of 4 random ids; engine table slot 0x58 returns an object (null in a quarter) with slots 0x74 (2 args), 0x2c and 0x138
(3 args); a has slot 0x288; seven stack arguments in all."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g462040(c):
    clear_hooks(c)
    r = c.rng

    def wstr(em, k):
        buf = em.arg32(0)
        n = r.randint(0, 60)
        em.wbytes(buf, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')

    def logstr(em, k):
        p = em.arg32(0)
        data = b''
        i = 0
        while i < 0x200:
            b = bytes(em.rbytes(p + i, 1))
            if b == b'\0':
                break
            data += b
            i += 1
        em.calllog.append(('str', data))
    hook_rec(c, 0x4e1070, 1, this=True, side=wstr, stackmark=(0,))
    hook_rec(c, 0x4e1b30, 0, ret=r.getrandbits(32), this=True, pop=0)
    hook_rec(c, 0x633654, 0, pop=0, ret=None)
    me = obj(c, 0x80, {0x2f4: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32), side=logstr, stackmark=(0,))}, nslots=0x2f8 // 4)
    return [me, rnd(c, 0x20)]


def _g464460(c):
    clear_hooks(c)
    r = c.rng

    def wtmp(em, k):
        if r.random() < 0.5:   # sometimes the slot leaves the zero initialisation of tmp alone
            em.w32(em.arg32(1), r.getrandbits(32))
    t = obj(c, 0x20, {0x88: pystub(c, 2, this=True, side=wtmp, stackmark=(1,))}, nslots=0x90 // 4)
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32)),
                           0x138: pystub(c, 0, ret=t, this=True), 0x4c: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    me = obj(c, 0x80, {0x12c: pystub(c, 3, this=True)}, nslots=0x130 // 4)
    f = 0 if r.random() < 0.5 else r.choice([1, 0x100, r.getrandbits(32) | 1])
    return [me, f]


def _g476b50(c):
    clear_hooks(c)
    r = c.rng
    obj_ = 0 if r.random() < 0.25 else obj(c, 0x20, {0x74: pystub(c, 2, this=True), 0x2c: pystub(c, 0, this=True), 0x138: pystub(c, 3, this=True)}, nslots=0x140 // 4)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=obj_, this=True)})
    a = obj(c, 0x20, {0x288: pystub(c, 3, this=True)}, nslots=0x290 // 4)
    me = rnd(c, 0x80)
    arr = rnd(c, 0x20)
    c.emu.w32(me + 0x68, arr)
    c.emu.w32(me + 0x60, r.choice([1, 1, 2, 3, 4]))
    c.emu.w32(me + 0x5c, r.randint(1, 4))
    return [me, a, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x462040, 'GUESS read two strings from a stream and resolve them', 'thiscall', None, ret='eax', gen=_g462040, note='batch34056')
S(0x464460, 'GUESS store a flag and when clear publish a table value', 'thiscall', None, ret=None, gen=_g464460, note='batch34056')
S(0x476b50, 'GUESS cycle to the next object, attach and configure it', 'thiscall', None, ret='eax', gen=_g476b50, note='batch34056')
