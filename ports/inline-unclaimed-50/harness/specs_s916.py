"""specs_s916.py - batch 916: 0x4f7210 (thiscall, one stack arg (stream), ret 4, returns al). Stand-ins (logged): 0x4fa230 (thiscall, stream;
returns a drawn bool; its body is not read yet, so this row is verified against the stand-in only), the stream's slots +0x40 (writes a
drawn dword to the pointer), +0x18 (writes n bytes), +0x50 and +0x68 (write dwords), and the manager's slot +0x58 (maps a value to a drawn
dword). The stream object and the manager are heap objects; the writes to this+0x8f .. +0xab are compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8
    mapv = {}

    def h4fa(e, rr):
        e.calllog.append(('4fa230', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    only_hooks(c, {0x4fa230: h4fa})

    def s40(e, rr):
        v = r.getrandbits(32)
        e.w32(e.arg32(0), v)
        e.calllog.append(('s.40', e.arg32(0) != 0, v))
        e.ret(eax=0, argbytes=4)

    def s18(e, rr):
        p, n = e.arg32(0), e.arg32(1)
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(n)))
        e.calllog.append(('s.18', n))
        e.ret(eax=0, argbytes=8)

    def s50(e, rr):
        e.w32(e.arg32(0), r.getrandbits(32))
        e.calllog.append(('s.50',))
        e.ret(eax=0, argbytes=4)

    def s68(e, rr):
        e.w32(e.arg32(0), r.getrandbits(32))
        e.calllog.append(('s.68',))
        e.ret(eax=0, argbytes=4)

    stream = vt_object(c, 0x40, {0x40: s40, 0x18: s18, 0x50: s50, 0x68: s68}, nslots=0x40, name='stream')

    def m58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=mapv.setdefault(k, r.getrandbits(32)), argbytes=4)

    mgr = vt_object(c, 0x1000, {0x58: m58}, nslots=0x40, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = rnd(c, 0x200)
    return [self, stream]


S(0x4f7210, 'read4f7210 (no name in map; 4fa230 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch916 (residue-9 slice)')
