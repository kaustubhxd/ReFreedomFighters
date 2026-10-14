"""specs_s34048.py - cascade tier E, batch 34048.
0x547670: like batch 34047's 0x546040 but slot 0x68: count -1..4, unaligned record pointer to 4*0x34 random bytes, slot recorder with heap pointer arguments.
0x559d40: hooked 0x5003d0 (returns an entry, call index chosen per call) and 0x5002f0 (thiscall recorder, the leftover argument is its value); this+0x1c object slot 0x20 returns an object (null in a quarter) whose slot
0x20 returns another (null in a quarter) whose slot 0x1e0 returns 0/1; engine table slot 0x4c returns a random value.
0x5612c0 (stdcall, ECX unused): buf holds a NUL-terminated string of 0..40 random bytes (nonzero) in a 0x100 block of random bytes; the object at [[engine table]+0xae4] has slot 0 returning a NUL-terminated string
of 0..40 bytes; the data word at 0x679e6c is the exe's own."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _g547670(c):
    clear_hooks(c)
    r = c.rng
    s = obj(c, 0x20, {0x68: pystub(c, 1, this=True)}, nslots=0x70 // 4)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x28, r.choice([-1, 0, 1, 2, 4, r.randint(0, 4)]) & 0xffffffff)
    c.emu.wbytes(me + 0xf, rnd(c, 4 * 0x34).to_bytes(4, 'little'))
    return [me, s]


def _g559d40(c):
    clear_hooks(c)
    r = c.rng
    e1, e2, e3 = rnd(c, 0x20), rnd(c, 0x20), rnd(c, 0x20)
    ents = [e1, e2]
    hook_rec(c, 0x5003d0, 1, ret=lambda em, k: ents[min(k, 1)], this=True)
    hook_rec(c, 0x5002f0, 1, this=True)
    r2 = 0 if r.random() < 0.25 else obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 1]) | (r.getrandbits(24) << 8), this=True)}, nslots=0x1f0 // 4)
    r1 = 0 if r.random() < 0.25 else obj(c, 0x20, {0x20: pystub(c, 0, ret=r2, this=True)}, nslots=0x30 // 4)
    m = obj(c, 0x20, {0x20: pystub(c, 0, ret=r1, this=True)}, nslots=0x30 // 4)
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=lambda em, k: r.getrandbits(32), this=True)})
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x1c, m)
    a = rnd(c, 0x20)
    c.emu.w32(a + 8, rnd(c, 0x10))
    return [me, a]


def _g5612c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cstr(maxlen):
        n = r.randint(0, maxlen)
        return bytes(r.randrange(1, 256) for _ in range(n)) + b'\0'
    s = rnd(c, 0x60)
    e.wbytes(s, cstr(40))
    comp = obj(c, 0x20, {0: pystub(c, 2, ret=s, this=True)}, nslots=4)
    so = sysobj(c, table_size=0xb00)
    tbl = e.r32(so + 0x9b)
    e.w32(tbl + 0xae4, comp)
    buf = rnd(c, 0x100)
    e.wbytes(buf, cstr(40))
    return [buf]


S(0x547670, 'GUESS write array of 0x34-byte records through slot 0x68', 'thiscall', None, ret='al', gen=_g547670, note='batch34048')
S(0x559d40, 'GUESS register an id and a table value', 'thiscall', None, ret=None, gen=_g559d40, note='batch34048')
S(0x5612c0, 'GUESS append separator and path component to a string', 'stdcall', None, ret=None, gen=_g5612c0, note='batch34048')
