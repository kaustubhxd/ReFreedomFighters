"""specs_s931.py - batch 931: 0x4386a0 (thiscall, two stack args (string, a2), ret 8, void). The string is drawn from letters, spaces, '+', '0' and
NUL-free text of up to 20 characters; a null pointer is drawn too. The block from 0x41e290 (stood in: a fixed 0x40-byte block) receives the copy;
0x4385e0 (stood in; thiscall, token, a2) logs the token text and a2; 0x634273 (stood in; cdecl, block, 1) logs the block text. Heap bytes compared."""
from pilot import S
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng
    blk = rnd(c, 0x40)
    e.wbytes(blk, bytes(0x40))

    def h290(e, rr):
        e.calllog.append(('alloc', e.arg32(0)))
        e.ret(eax=blk, argbytes=0)

    def h5e0(e, rr):
        tok = e.rbytes(e.arg32(0), 24).split(b'\0')[0]
        e.calllog.append(('token', tok, e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    def h273(e, rr):
        txt = e.rbytes(e.arg32(0), 40).split(b'\0')[0]
        e.calllog.append(('634273', txt, e.arg32(1)))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x41e290: h290, 0x4385e0: h5e0, 0x634273: h273})
    alphabet = b'ab+ 0+ c+d 9+'
    if r.random() < 0.1:
        s = 0
    else:
        s = e.cstr(''.join(chr(r.choice(alphabet)) for _ in range(r.randint(0, 20))))
    self = rnd(c, 0x40)
    return [self, s, r.getrandbits(32)]


S(0x4386a0, 'tokenize4386a0 (named? no; core claim)', 'thiscall', None, ret=None, gen=_gen, note='area50 batch931 (core slice)')
