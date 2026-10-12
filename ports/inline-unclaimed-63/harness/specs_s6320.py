"""specs_s6320.py - unclaimed-63 batch 20 (docs/20-unclaimed-63.md): 0x49b3a0 (ZSaveGame::bool_pack, eight stack bools, ret 0x20)
and 0x4ccfe0 (REFTAB::~REFTAB, thiscall, ret). Stubs, rewritten each case (with a flush):
  * bool_pack: this's vtable slot +0x10 records the byte its pointer argument points to, its second argument (1) and ECX, ret 8;
    the eight bool arguments are random 32-bit values, zero in about half the cases (only the low byte matters);
  * REFTAB: the list at this+4 has 0 to 3 nodes (node+4 is the next, 0 at the end), the vptr is set to 0x695734 by the function, so
    the stub is written into that vtable's slot +0x7c (in the image): it records its argument (the node) in a ring and overwrites
    the node's next pointer with garbage, so reading next after the call fails. The image slot is restored by the harness per case."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen_pack(c):
    self_ = _rnd(c, 0x40)
    vt = c.emu.alloc(0x200, 4)
    cc = _cell(c, 3)
    # mov eax,[esp+4]; movzx eax, byte [eax]; mov [cc],eax; mov eax,[esp+8]; mov [cc+4],eax; mov [cc+8],ecx; ret 8
    code = (b'\x8b\x44\x24\x04' + b'\x0f\xb6\x00' + b'\xa3' + _le(cc) +
            b'\x8b\x44\x24\x08' + b'\xa3' + _le(cc + 4) + b'\x89\x0d' + _le(cc + 8) + b'\xc2\x08\x00')
    c.emu.w32(vt + 0x10, _stub(c, code))
    c.emu.w32(self_, vt)
    args = []
    for _ in range(8):
        args.append(0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [self_] + args


def _gen_refdtor(c):
    self_ = _rnd(c, 0x40)
    nnodes = c.rng.randint(0, 3)
    nodes = [_rnd(c, 0x40) for _ in range(nnodes)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 4, nodes[i + 1] if i + 1 < nnodes else 0)
    c.emu.w32(self_ + 4, nodes[0] if nodes else 0)
    c.emu.w32(self_ + 0x14, c.rng.getrandbits(32))
    cring = _cell(c, 4)
    cnt = _cell(c)
    garbage = c.rng.getrandbits(32) | 1
    # the vtable 0x695734 slot +0x7c (in the image): records the node in a ring, clobbers node+4, bumps the count, ret 4
    code = (b'\x8b\x44\x24\x04' + b'\x8b\x15' + _le(cnt) + b'\x89\x04\x95' + _le(cring) +
            b'\xc7\x40\x04' + _le(garbage) + b'\xff\x05' + _le(cnt) + b'\xc2\x04\x00')
    c.emu.w32(0x695734 + 0x7c, _stub(c, code))
    _flush(c)
    return [self_]


S(0x49b3a0, 'ZSaveGame::bool_pack (GC name) thiscall', 'thiscall', None, ret=None, gen=_gen_pack,
  note='unclaimed-63 batch 20; vtbl+0x10 stub records the byte, arg 2 and ECX; eight stack bools, ret 0x20')
S(0x4ccfe0, 'REFTAB::~REFTAB (GC name) thiscall', 'thiscall', None, ret=None, gen=_gen_refdtor,
  note='unclaimed-63 batch 20; SEH frame not reproduced; vtbl 0x695734 +0x7c stub in the image')
