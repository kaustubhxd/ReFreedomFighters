"""specs_s35103.py - 0x46eac0 (thiscall, no args, ret='eax'). [this+0xcb] (unaligned) random id; engine table slot 0x58 (1 arg recorded) returns e or 0 in 1/5; e: [e+4] name pointer (null in a third), [e+0xc] block whose unaligned dword at +0x23 has bit 0x100000 in 2/3, vtable slot 0x25c
(2 args, returns zero in a third); logger at 0x700390 (slot 0x20 -> object with a custom slot 0x30 stub logging the vtable-ecx, three args and the name string; the log object's slot 0x20 records the line number)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g46eac0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x40)
    fl = r.getrandbits(32)
    fl = (fl | 0x100000) if r.random() < 2 / 3 else (fl & ~0x100000)
    e.wbytes(blk + 0x23, fl.to_bytes(4, 'little'))
    ent = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=0 if r.random() < 1 / 3 else r.getrandbits(32) | 1)}, nslots=0x98)
    e.w32(ent + 0xc, blk)
    if r.random() < 1 / 3:
        e.w32(ent + 4, 0)
    else:
        nm = rnd(c, 0x10)
        e.wbytes(nm, bytes(r.choice(b'abcXYZ') for _ in range(r.randint(0, 6))) + b'\0')
        e.w32(ent + 4, nm)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=0 if r.random() < 0.2 else ent)})

    def rds(em, p):
        s = b''
        while len(s) < 24 and 0x1000 <= p:
            ch = bytes(em.rbytes(p + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        return s

    def l30(em, rr):
        em.calllog.append(('slot30', em.reg('ecx'), em.arg32(0), em.arg32(1), rds(em, em.arg32(2)) if em.arg32(2) != 0x67c8e8 else b'<default>'))
        em.ret(eax=0)
    lg2 = obj(c, 0x20, {0x30: e.stub_fn('slot30', l30)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    me = rnd(c, 0xd0)
    return [me]


S(0x46eac0, 'GUESS look up sub-resource with error logs', 'thiscall', None, ret='eax', gen=_g46eac0, note='batch35103')
