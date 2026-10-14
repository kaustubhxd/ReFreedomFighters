"""specs_s1419.py - unclaimed-14 batch 19 (residue 13): ZBombDamageList::CopyData (0x5dbe50, thiscall, one stack argument, ret 4).

Source list L (src+0x48): slot +0x4c writes tmp = 1 (checksum stub, callee pops). Slot +0x5c is a small machine-code stub
with a counter: while the counter is nonzero it decrements it, sets *tmp = 1 and returns the item; when it is zero it sets
*tmp = 0 and returns the item. The item is a random value each case. The count is 0..3 (0 means the copy loop does not run).
Destination D (this+0x48): slot +4 takes the item (checksum stub). A null src+0x48 (about 1 case in 8) returns at once.
Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _P(v):
    return struct.pack('<I', v & 0xffffffff)


def _bomb(c):
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, c.rng.randint(0, 3))
    item = c.rng.getrandbits(32)
    b = b'\x8b\x44\x24\x04'          # mov eax,[esp+4]        (tmp)
    b += b'\x8b\x15' + _P(cnt)       # mov edx,[cnt]
    b += b'\x85\xd2'                 # test edx,edx
    b += b'\x74\x15'                 # je zero (21 bytes ahead)
    b += b'\x4a'                     # dec edx
    b += b'\x89\x15' + _P(cnt)       # mov [cnt],edx
    b += b'\xc7\x00\x01\x00\x00\x00' # mov dword [eax],1
    b += b'\xb8' + _P(item)          # mov eax,item
    b += b'\xc2\x04\x00'             # ret 4
    b += b'\xc7\x00\x00\x00\x00\x00' # zero: mov dword [eax],0
    b += b'\xb8' + _P(item)          # mov eax,item
    b += b'\xc2\x04\x00'             # ret 4
    vt_l = c.emu.alloc(0x100, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, writes=[(1, 0, 1)])
    c.emu.w32(vt_l + 0x4c, s)
    c.emu.w32(vt_l + 0x5c, ss.code(c, b))
    lst = _rnd(c, 0x100)
    c.emu.w32(lst, vt_l)
    vt_d = c.emu.alloc(0x100, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False)
    c.emu.w32(vt_d + 4, s)
    d = _rnd(c, 0x100)
    c.emu.w32(d, vt_d)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x48, d)
    src = _rnd(c, 0x100)
    c.emu.w32(src + 0x48, 0 if c.rng.random() < 0.125 else lst)
    return [self_, src]


S(0x5dbe50, 'ZBombDamageList::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_bomb,
  note='unclaimed-14 batch 19 (residue 13); source list slots +0x4c (checksum) and +0x5c (counter stub); dest +4 (checksum)')
