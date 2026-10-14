"""specs_s37036.py - cascade s6 batch 37036: 0x4d3090 (record packer). Scripted stream: slot 0x18 serves the next length (4-byte request) or payload (other sizes), -1 at the end;
slot 0x40 writes a type id 0..3. Arena at this+8 holds entries {size >= 0x11, valid byte, data}; 0x4d2b40 returns one of them or 0 (size-matching records are generated);
memmove (IAT 0x676278) and the memcpy thunk 0x634d22 do real copies; slot 0xc of this and the logger are stubs."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d3090(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(2))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))

    def cp(em, k):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n < 0x400:
            em.wbytes(d, em.rbytes(s, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp, stackmark=(1,))
    e.w32(0x676278, pystub(c, 3, pop=0, side=cp))
    # arena
    arena = e.alloc(0x400, 4)
    ents = []
    used = 0
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        sz = r.randint(0x11, 0x24)
        e.wbytes(arena + used, bytes(r.getrandbits(8) for _ in range(sz)))
        e.w32(arena + used, sz)
        e.wbytes(arena + used + 4, bytes([r.choice([0, 1, 1])]))
        ents.append((arena + used, sz))
        used += sz
    cap = used + r.choice([0, 10, 0x20, 0x40, 0x100])
    validsum = sum(sz for a, sz in ents if e.rbytes(a + 4, 1) != b'\0')
    # records
    recs = []
    ret_ents = []
    for _ in range(r.choice([0, 1, 2, 3])):
        if ents and r.random() < 0.4:
            ea, sz = r.choice(ents)
            b0, b8 = 0, sz - 0x11
            ret_ents.append(ea)
        else:
            b0, b8 = r.randint(0, 8), r.randint(0, 0x10)
            ret_ents.append(r.choice([0, 0, ents[0][0] if ents else 0]))
        total = b8 + 0x11 + b0
        ln = max(total, 0x20) + r.choice([0, 3, 0x10])
        payload = bytearray(r.getrandbits(8) for _ in range(ln))
        payload[0:4] = b0.to_bytes(4, 'little')
        payload[8:12] = b8.to_bytes(4, 'little')
        recs.append(bytes(payload))
    if recs:
        t0 = int.from_bytes(recs[0][8:12], 'little') + 0x11 + int.from_bytes(recs[0][0:4], 'little')
        if r.random() < 0.3:
            cap = r.choice([used + t0, validsum + t0, validsum + t0 - 1, used + t0 - 1])
    st = {'i': 0, 'cur': 0, 'ty': 0}

    def read(em, k):
        buf, n = em.arg32(0), em.arg32(1)
        if n == 4:
            i = st['i']
            if i < len(recs):
                em.w32(buf, len(recs[i]))
                st['cur'] = i
                st['i'] += 1
            else:
                em.w32(buf, 0xffffffff)
            return 0
        em.wbytes(buf, recs[st['cur']][:n].ljust(n, b'\0'))
        return 0

    def lookup(em, k):
        me_ = em.reg('ecx')
        base, usedn = em.r32(me_ + 8), em.r32(me_ + 0xc)
        buf = em.arg32(0) - 0xc
        total = em.r32(buf + 8) + 0x11 + em.r32(buf)
        found = []
        off = 0
        while off < usedn:
            sz = em.r32(base + off)
            if sz < 6:
                break
            found.append((base + off, sz))
            off += sz
        match = [a for a, sz in found if sz == total]
        if match and r.random() < 0.7:
            return match[0]
        if found and r.random() < 0.4:
            return r.choice(found)[0]
        return 0
    hook_rec(c, 0x4d2b40, 2, this=True, ret=lookup, pop=8, stackmark=(0,))
    stream = obj(c, 0x40, {0x18: pystub(c, 2, this=True, nullflag=(0,), ret=read),
                           0x40: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), r.randrange(4)))})
    me = obj(c, 0x40, {0xc: pystub(c, 0, this=True)})
    e.w32(me + 8, arena)
    e.w32(me + 0xc, used)
    e.w32(me + 4, cap)
    return [me, stream]


S(0x4d3090, 'GUESS pack stream records into arena', 'thiscall', None, ret=None, gen=_g4d3090, note='batch37036')
