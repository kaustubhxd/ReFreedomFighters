"""specs_s35096.py - 0x4d36b0 (thiscall, no args). this: random 0x20 bytes; [+8] = block area of 0x200 bytes holding up to 4 blocks (first dword = size 0x20..0x60, byte +4 in use in half); [+0xc] = total size (the exact sum of the block sizes, or zero in 1/6); [+4] random;
0x4d29d0 hooked (thiscall); logger at 0x700390: slot 0x20 (2 args, recorded: the line number) -> object with a custom slot 0x2c stub (caller-popped) that logs its three words and the C string behind the third argument when it points into the block area."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d36b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4d29d0, 0, this=True)
    area = rnd(c, 0x300)
    nb = r.choice([0, 1, 2, 3, 4])
    off = 0
    for _ in range(nb):
        sz = r.choice([0x20, 0x28, 0x30, 0x40, 0x60])
        e.w32(area + off, sz)
        e.wbytes(area + off + 4, bytes([0 if r.random() < 0.5 else r.randint(1, 255)]))
        e.wbytes(area + off + 0x11, bytes(r.choice(b'abcdef') for _ in range(r.randint(0, 8))) + b'\0')
        off += sz
    total = off if r.random() < 5 / 6 else 0

    def l2c(em, rr):
        a = em.arg32(2)
        s = b''
        if area <= a < area + 0x300:
            while len(s) < 20:
                ch = bytes(em.rbytes(a + len(s), 1))
                if ch == b'\0':
                    break
                s += ch
        em.calllog.append(('slot2c', em.reg('ecx'), em.arg32(0), em.arg32(1), a if not (area <= a < area + 0x300) else ('txt', s)))
        em.ret(eax=0)
    lg2 = obj(c, 0x20, {0x2c: e.stub_fn('slot2c', l2c)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    me = rnd(c, 0x20)
    e.w32(me + 8, area)
    e.w32(me + 0xc, total)
    return [me]


S(0x4d36b0, 'GUESS report blocks in use and free size', 'thiscall', None, ret=None, gen=_g4d36b0, note='batch35096')
