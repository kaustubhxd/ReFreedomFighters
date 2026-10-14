"""specs_s34065.py - cascade tier E, batch 34065.
0x4f4220: s slots 0x40 (heap pointers) and 0x30 (returns a different random value per call); this slots 0x248 (1 arg) and 0x23c (2 args) record; [this+0x18] random; unaligned fields +0x2a, +0x2e, +0x32, +0x36, +0x3a.
0x530fd0: n includes 0, 1, 3, 40, 0xffff (the largest valid), 0x10000 and 0x20000 (assert path through the logger object at 0x700390, count clamped to 0xffff) and negative values; hooked 0x41e290 (cdecl) returns a zero-filled
block big enough for the requested count; the table is compared through the heap.
0x533110: [this+0x548a] (unaligned) points at a zero-filled 0xa300-byte object with a vtable (slot 0x68: two args, logs the string behind its second (stack) pointer); the unaligned dwords at +0x8031 / +0xa269 start random
and must come back; [o+0x802d] points at a NUL-terminated string of 0..200 bytes; this slot 0x1f8 logs the two saved fields as they are while it runs; the /GS check is a recorder."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g4f4220(c):
    clear_hooks(c)
    r = c.rng
    s = obj(c, 0x20, {0x40: pystub(c, 1, this=True), 0x30: pystub(c, 0, ret=lambda em, k: r.getrandbits(32), this=True)}, nslots=0x44 // 4)
    me = obj(c, 0xa0, {0x248: pystub(c, 1, this=True), 0x23c: pystub(c, 2, this=True)}, nslots=0x250 // 4)
    c.emu.w32(me + 0x18, r.choice([0, 1, 2, r.getrandbits(32)]))
    return [me, s]


def _g530fd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 3, 40, 0xffff, 0x10000, -1, -5, r.randint(0, 40)] + [r.randint(0, 40)] * 40)   # the huge counts are rare: each one walks 65535 entries
    cnt = min(n, 0xffff) & 0xffff if n >= 0 else n & 0xffff
    if n > 0xffff:
        cnt = 0xffff
    buf = e.alloc(cnt * 0x15 + 0x20, 4)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x30 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x24 // 4)
    e.w32(0x700390, lg)
    return [rnd(c, 0xa0), n & 0xffffffff]


def _g533110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def logstr(em, k):
        p = em.arg32(1)
        data = b''
        i = 0
        while i < 0x104:
            b = bytes(em.rbytes(p + i, 1))
            if b == b'\0':
                break
            data += b
            i += 1
        em.calllog.append(('str', data))
    hook_rec(c, 0x633654, 0, pop=0)
    o = e.alloc(0xa300, 4)
    vt = e.alloc(0x70, 4)
    e.w32(vt + 0x68, pystub(c, 2, this=True, side=logstr, stackmark=(1,)))
    e.w32(o, vt)
    st = e.alloc(0x100, 4)
    e.wbytes(st, bytes(r.randrange(1, 256) for _ in range(r.randint(0, 200))) + b'\0')
    e.wbytes(o + 0x802d, st.to_bytes(4, 'little'))
    e.wbytes(o + 0x8031, r.getrandbits(32).to_bytes(4, 'little'))
    e.wbytes(o + 0xa269, r.getrandbits(32).to_bytes(4, 'little'))
    def during(em, k):   # the two saved fields must be zero while the callee runs
        em.calllog.append(('during', tuple(bytes(em.rbytes(o + off, 4)) for off in (0x8031, 0xa269))))
    me = obj(c, 0x5500, {0x1f8: pystub(c, 0, this=True, side=during)}, nslots=0x200 // 4)
    e.wbytes(me + 0x548a, o.to_bytes(4, 'little'))
    return [me]


S(0x4f4220, 'GUESS read a record from a stream and flip a flag', 'thiscall', None, ret=None, gen=_g4f4220, note='batch34065')
S(0x530fd0, 'GUESS allocate and initialise a table of 0x15-byte entries', 'thiscall', None, ret=None, gen=_g530fd0, note='batch34065')
S(0x533110, 'GUESS re-issue a stored string with two fields saved and restored', 'thiscall', None, ret=None, gen=_g533110, note='batch34065')
